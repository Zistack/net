template <typename InputStream>
std::string
getSegment (InputStream && input_stream)
{
	return getClassDecode
	(
		std::forward <InputStream> (input_stream),
		Class::pchar
	);
}
