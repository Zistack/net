T::T (const SectionSpec::T & spec)
{
	for (const MemberSpec::T & member_spec : spec.members)
	{
		this->members[member_spec.identifier] = {
		    member_spec.optional, member_spec.type, member_spec.default_value};
	}
}
