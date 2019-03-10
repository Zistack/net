template <typename InputStream>
std::string
T::getUserInfo (InputStream && input_stream)
{
	return Rule::getClassDecode (
	    std::forward<InputStream> (input_stream), Class::uichar);
}
