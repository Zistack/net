template <typename Interface, typename ... UpgradeArguments>
const Interface &
T <Interface, UpgradeArguments ...>::interface () const
{
	return static_cast <Interface &> (* this);
}

template <typename Interface, typename ... UpgradeArguments>
Interface &
T <Interface, UpgradeArguments ...>::interface ()
{
	return static_cast <Interface &> (* this);
}
