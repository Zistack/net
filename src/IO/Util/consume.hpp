template <typename Rule>
typename std::invoke_result<Rule, String::Reader::T>::type
consume (const std::string & string, Rule && rule)
{
	String::Reader::T input_stream (string);

	return consume (input_stream, std::forward<Rule> (rule));
}

template <typename InputStream,
    typename Rule,
    typename
#ifndef IO_Util_consume_hpp_2
#define IO_Util_consume_hpp_2
    = typename std::enable_if<!std::is_void<
        typename std::invoke_result<Rule, InputStream>::type>::value>::type
#endif /* IO_Util_consume_hpp_2 */
    >
typename std::invoke_result<Rule, InputStream>::type
consume (InputStream && input_stream, Rule && rule)
{
	auto result = rule (std::forward<InputStream> (input_stream));

	if (!input_stream.eof ())
	{
		throw Failure::SyntaxError::T (
		    Message::unexpectedCharacter (input_stream.peek ()));
	}

	return result;
}

template <typename InputStream,
    typename Rule,
    typename
#ifndef IO_Util_consume_hpp_3
#define IO_Util_consume_hpp_3
    = typename std::enable_if<std::is_void<
        typename std::invoke_result<Rule, InputStream>::type>::value>::type
#endif /* IO_Util_consume_hpp_3 */
    >
void
consume (InputStream && input_stream, Rule && rule)
{
	rule (std::forward<InputStream> (input_stream));

	if (!input_stream.eof ())
	{
		throw Failure::SyntaxError::T (
		    Message::unexpectedCharacter (input_stream.peek ()));
	}
}
