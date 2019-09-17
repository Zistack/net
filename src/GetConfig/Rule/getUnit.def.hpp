template <typename InputStream>
std::string
getUnit (InputStream && input_stream)
{
	std::string unit = IO::Rule::getClass
	(
		std::forward <InputStream> (input_stream),
		IO::Class::alpha
	);

	if (unit . empty ()) throw Failure::SyntaxError::T ("Expected unit\n");

	return unit;
}
