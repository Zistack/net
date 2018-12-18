template <class Rule>
decltype (std::declval<Rule> () (
    std::declval<IO::Interface::PeekableInputStream::T &> ()))
consume (const std::string & input_string, Rule && rule)
{
	std::string::size_type pointer;
	String::PeekableInputStream::T input_stream (input_string, pointer);

	return consume (input_stream, std::forward<Rule> (rule));
}

template <class Rule,
    typename
#ifndef IO_Util_consume_hpp_2
#define IO_Util_consume_hpp_2
    = typename std::enable_if<!std::is_void<typename std::invoke_result<Rule,
        IO::Interface::PeekableInputStream::T &>::type>::value>::type
#endif /* IO_Util_consume_hpp_2 */
    >
typename std::invoke_result<Rule, IO::Interface::PeekableInputStream::T &>::type
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

template <class Rule,
    typename
#ifndef IO_Util_consume_hpp_3
#define IO_Util_consume_hpp_3
    = typename std::enable_if<std::is_void<typename std::invoke_result<Rule,
        IO::Interface::PeekableInputStream::T &>::type>::value>::type
#endif /* IO_Util_consume_hpp_3 */
    >
void
consume (IO::Interface::PeekableInputStream::T & input_stream, Rule && rule)
{
	rule (input_stream);

	if (!input_stream.eof ())
	{
		throw Failure::SyntaxError::T (
		    Message::unexpectedCharacter (input_stream.peek ()));
	}
}
