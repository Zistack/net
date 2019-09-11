T::T (const std::string & field_value)
{
	IO::String::Reader::T input_stream (field_value);
	this -> content_length = IO::Rule::getUInt (input_stream);
	IO::Util::expectEOF (input_stream);
}
