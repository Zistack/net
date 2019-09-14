template <typename V, typename ... Members>
template <typename InputStream>
typename T <V, Members ...>::Value
T <V, Members ...>::readFrom (InputStream && input_stream)
{
	return Value (std::forward <InputStream> (input_stream));
}
