template <bool upgrade_required>
void
validateServerUpgradeCondition
(
	bool condition,
	const std::string & fail_message,
	const HTTP::HeaderMap::T & fail_headers = {}
);
