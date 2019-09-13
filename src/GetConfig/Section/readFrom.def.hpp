template <typename ... Members>
template <typename InputStream>
typename T <Members ...>::Value
T <Members ...>::readFrom (InputStream && input_stream)
{
	return T (std::forward <InputStream> (input_stream));
}
