template <typename InputStream>
std::string
getQuotedString (InputStream && input_stream)
{
	std::string quoted_string;

	IO::Util::expect (std::forward <InputStream> (input_stream), '"');

	while (true)
	{
		char c = input_stream . peek ();

		if (c == '"')
		{
			input_stream . get ();
			return quoted_string;
		};

		if (c == '\\')
		{
			input_stream . get ();
			quoted_string . push_back
			(
				IO::Util::expect
				(
					std::forward <InputStream> (input_stream),
					Class::text
				)
			);
		}

		quoted_string . push_back
		(
			IO::Util::expect
			(
				std::forward <InputStream> (input_stream),
				Class::text
			)
		);
	}
}
