template <typename InputStream>
std::string
T::getFragmentPart (InputStream && input_stream)
{
	return IO::Rule::getClass
	(
		std::forward <InputStream> (input_stream),
		Class::fchar
	);
}
