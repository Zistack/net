template <typename Responder, typename ... UpgradeTargets>
void
T <Responder, UpgradeTargets ...>::cancel ()
{
	std::unique_lock upgrade_lock (this -> details () . m_upgrade_mutex);

	this -> Base::T <Responder, UpgradeTargets ...>::cancel ();

	this -> m_cancelled = true;

	std::optional
	<
		typename Details::T <Responder, UpgradeTargets ...>::UpgradeProtocol
	> & upgrade_protocol =
		this -> details () . m_upgrade_protocol;

	if (upgrade_protocol)
	{
		std::visit
		(
			[&] (auto && new_protocol) { new_protocol -> cancel (); },
			* upgrade_protocol
		);
	}
}
