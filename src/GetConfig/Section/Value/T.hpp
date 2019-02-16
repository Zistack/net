T::T (const Spec::T & spec,
    IO::Interface::PeekableInputStream::T & input_stream)
{
	for (const GetConfig::Member::Spec::T & member_spec : spec.members)
	{
		this->members[member_spec.identifier] = {
		    member_spec.optional, member_spec.type, member_spec.default_value};
	}

	this->readFrom (input_stream);
}
