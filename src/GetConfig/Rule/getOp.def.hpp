template <typename InputStream>
std::string
getOp (InputStream && input_stream)
{
	return IO::Rule::getClass
	(
		std::forward <InputStream> (input_stream),
		IO::Class::alpha
	);
}
