template <typename Interface, typename ... UpgradeTargets>
const T <Interface, UpgradeTargets ...> &
T <Interface, UpgradeTargets ...>::http () const
{
	return * this;
}

template <typename Interface, typename ... UpgradeTargets>
T <Interface, UpgradeTargets ...> &
T <Interface, UpgradeTargets ...>::http ()
{
	return * this;
}
