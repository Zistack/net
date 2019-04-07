template <typename InputStream>
std::string
getVChars (InputStream && input_stream)
{
	return IO::Rule::getClass
	(
		std::forward <InputStream> (input_stream),
		Class::vchar
	);
}
