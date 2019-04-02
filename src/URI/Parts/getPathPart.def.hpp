template <typename InputStream>
std::string
T::getPathPart (InputStream && input_stream)
{
	return IO::Rule::getNotClass
	(
		std::forward <InputStream> (input_stream),
		Class::thirdDelimiter
	);
}
