template <class Rule>
decltype (std::declval<Rule> () (
    std::declval<IO::Interface::PeekableInputStream::T &> ()))
consume (const std::string & input_string, Rule && rule)
{
	std::string::size_type pointer;
	String::PeekableInputStream::T input_stream (input_string, pointer);

	return consume (input_stream, std::forward<Rule> (rule));
}

template <class Rule>
decltype (std::declval<Rule> () (
    std::declval<IO::Interface::PeekableInputStream::T &> ()))
consume (IO::Interface::PeekableInputStream::T & input_stream, Rule && rule)
{
	auto result = rule (input_stream);

	if (!input_stream.eof ())
	{
		throw Failure::SyntaxError::T (
		    Message::unexpectedCharacter (input_stream.peek ()));
	}

	return result;
}
