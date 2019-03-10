template <typename InputStream>
std::string
getFragment (InputStream && input_stream)
{
	return getClassDecode (
	    std::forward<InputStream> (input_stream), Class::fchar);
}
