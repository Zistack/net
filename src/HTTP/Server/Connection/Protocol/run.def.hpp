template <typename Interface, typename ... UpgradeTargets>
template <typename InputStream, typename OutputStream>
void
T <Interface, UpgradeTargets ...>::run
(
	InputStream && input_stream,
	OutputStream && output_stream
)
{
	this -> FIFOProtocolInterface::T <Interface, UpgradeTargets ...>::run
	(
		std::forward <InputStream> (input_stream),
		std::forward <OutputStream> (output_stream)
	);

	std::unique_lock upgrade_lock (this -> m_upgrade_mutex);

	if (this -> m_cancelled) return;

	std::optional <typename T::UpgradeProtocol > & upgrade_protocol =
		this -> m_upgrade_protocol;

	std::exception_ptr e;

	if (upgrade_protocol)
	{
		std::visit
		(
			[&] (auto && upgrade_protocol)
			{
				upgrade_protocol -> prime ();

				upgrade_lock . unlock ();

				try
				{
					upgrade_protocol -> run
					(
						std::forward <InputStream> (input_stream),
						std::forward <OutputStream> (output_stream)
					);
				}
				catch (...)
				{
					e = std::current_exception ();
				}

				upgrade_lock . lock ();
			},
			* upgrade_protocol
		);
	}

	this -> m_upgrade_protocol = std::nullopt;

	if (e) std::rethrow_exception (e);
}
