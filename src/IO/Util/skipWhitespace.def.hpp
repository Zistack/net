template <typename PeekableInputStream>
void
skipWhitespace (PeekableInputStream && input_stream)
{
	while
	(
		test
		(
			std::forward <PeekableInputStream> (input_stream),
			Class::whitespace
		)
	)
	{
		input_stream.get ();
	}
}
