template <typename Responder, typename ... UpgradeTargets>
template <typename InputStream, typename OutputStream>
void
T <Responder, UpgradeTargets ...>::run
(
	InputStream && input_stream,
	OutputStream && output_stream
)
{
	this -> Base::T <Responder, UpgradeTargets ...>::run
	(
		std::forward <InputStream> (input_stream),
		std::forward <OutputStream> (output_stream)
	);

	std::unique_lock upgrade_lock (this -> details () . m_unique_lock);

	if (this -> m_cancelled) return;

	std::optional
	<
		typename Details::T <Responder, UpgradeTargets ...>::UpgradeProtocol
	> &
	upgrade_protocol = this -> details () . m_upgrade_protocol;

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

	this -> details () . m_upgrade_protocol = std::nullopt;

	if (e) std::rethrow_exception (e);
}
