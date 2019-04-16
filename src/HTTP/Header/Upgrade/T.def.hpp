T::T (const std::string field_value)
{
	IO::String::Reader::T input_stream (field_value);

	this -> protocols = Rule::getList
	(
		input_stream,
		[] (auto & input_stream) { return Protocol::T (input_stream); }
	);

	IO::Util::expectEOF (input_stream);
	if (this -> protocols . size () < 1)
	{
		throw Failure::SemanticError::T
		(
			"Upgrade header must be supplied with at least one protocol"
		);
	}
}
