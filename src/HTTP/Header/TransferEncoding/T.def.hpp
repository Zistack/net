T::T (const std::string & field_value)
{
	IO::String::Reader::T input_stream (field_value);
	auto parseSpecification = [] (auto && input_stream)
	{
		using InputStream = decltype (input_stream);

		return Specification::T (std::forward <InputStream> (input_stream));
	};

	IO::String::T transfer_encoding_streams (field_value);
	this -> specifications = Rule::getList (input_stream, parseSpecification);
	IO::Util::expectEOF (input_stream);
}
