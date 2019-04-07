template <typename InputStream>
std::string
getText (InputStream && input_stream)
{
	return IO::Rule::getClass
	(
		std::forward <InputStream> (input_stream),
		Class::text
	);
}
