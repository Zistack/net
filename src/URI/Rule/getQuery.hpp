template <typename InputStream>
std::string
getQuery (InputStream && input_stream)
{
	return getClassDecode (
	    std::forward<InputStream> (input_stream), Class::qchar);
}
