template <typename InputStream>
void
skipWhitespace (InputStream && input_stream)
{
	while (true)
	{
		if
		(
			IO::Util::test
			(
				std::forward <InputStream> (input_stream),
				IO::Class::whitespace
			)
		)
		{
			input_stream . get ();
		}
		else if
		(
			IO::Util::test (std::forward <InputStream> (input_stream), '#')
		)
		{
			while
			(
				! IO::Util::test
				(
					std::forward <InputStream> (input_stream),
					'\n'
				)
			)
			{
				input_stream . get ();
			}
		}
		else
		{
			return;
		}
	}
}
