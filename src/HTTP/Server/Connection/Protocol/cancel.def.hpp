template <typename Interface, typename ... UpgradeTargets>
void
T <Interface, UpgradeTargets ...>::cancel ()
{
	std::unique_lock upgrade_lock (this -> m_upgrade_mutex);

	this -> FIFOProtocolInterface::T <Interface, UpgradeTargets ...>::cancel ();

	this -> m_cancelled = true;

	std::optional <typename T::UpgradeProtocol> & upgrade_protocol =
		this -> m_upgrade_protocol;

	if (upgrade_protocol)
	{
		std::visit
		(
			[&] (auto && new_protocol) { new_protocol -> cancel (); },
			* upgrade_protocol
		);
	}
}
