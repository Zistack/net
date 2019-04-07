template <typename InputStream>
void
skipWhitespace (InputStream && input_stream)
{
	while
	(
		IO::Util::test
		(
			std::forward <InputStream> (input_stream),
			Class::whitespace
		)
	)
	{
		input_stream . get ();
	}
}
