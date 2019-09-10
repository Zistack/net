T::T (const std::string & field_value)
{
	IO::String::Reader::T input_stream (field_value);

	auto && options_list = Rule::getList
	(
		input_stream,
		[] (auto & input_stream)
		{
			return Util::normalize (Rule::getToken (input_stream));
		}
	);
	this -> options = std::unordered_set <std::string>
	(
		options_list . begin (),
		options_list . end ()
	);

	IO::Util::expectEOF (input_stream);
	if (this -> options . size () < 1)
	{
		throw Failure::SemanticError::T
		(
			"Connection header must be supplied with at least one option\n"
		);
	}
}
