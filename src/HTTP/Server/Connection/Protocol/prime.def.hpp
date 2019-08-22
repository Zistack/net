template <typename Responder, typename ... UpgradeTargets>
void
T <Responder, UpgradeTargets ...>::prime ()
{
	this -> Base::T <Responder, UpgradeTargets ...>::prime ();
}
