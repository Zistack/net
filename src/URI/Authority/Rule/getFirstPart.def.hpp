template <typename InputStream>
std::string
getFirstPart (InputStream && input_stream)
{
	return IO::Rule::getNotClass
	(
		std::forward <InputStream> (input_stream),
		'@'
	);
}
