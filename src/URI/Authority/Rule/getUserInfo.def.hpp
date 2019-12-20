template <typename InputStream>
std::string
getUserInfo (InputStream && input_stream)
{
	return URI::Rule::getClassDecode
	(
		std::forward <InputStream> (input_stream),
		Class::uichar
	);
}
