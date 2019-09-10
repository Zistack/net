template <bool upgrade_required>
void
validateServerUpgradeCondition
(
	bool condition,
	const std::string & fail_message,
	const HTTP::HeaderMap::T & fail_headers
)
{
	if (! condition)
	{
		throw HTTP::CodeError::T
		(
			upgrade_required ? 426 : 400,
			fail_message,
			fail_headers
		);
	}
}
