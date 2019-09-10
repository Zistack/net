void
validateClientUpgradeCondition
(
	bool condition,
	const std::string & fail_message
)
{
	if (! condition)
	{
		throw Failure::SemanticError::T (fail_message);
	}
}
