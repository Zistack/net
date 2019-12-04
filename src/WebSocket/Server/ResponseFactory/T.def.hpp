template <bool upgrade_required>
T <upgrade_required>::T (const HTTP::Request::T & request)
:	response (createUpgradeResponse (request))
{
}
