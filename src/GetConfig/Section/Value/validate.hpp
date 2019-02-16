void
T::validate () const
{
	for (auto [identifier, member] : this->members)
	{
		if ((!member.optional) && (!member.value))
		{
			throw Failure::SemanticError::T (
			    "Member '" + identifier + "' requires a value\n");
		}

		member.type->validate (*member.value);
	}
}
