template <typename InputStream>
void
T::init (InputStream && input_stream)
{
	std::string first_part = getFirstPart
	(
		std::forward <InputStream> (input_stream)
	);

	if (IO::Util::test (std::forward <InputStream> (input_stream), ':'))
	{
		this -> scheme = first_part;

		input_stream . get ();

		if (IO::Util::test (std::forward <InputStream> (input_stream), '/'))
		{
			input_stream . get ();

			if (IO::Util::test (std::forward <InputStream> (input_stream), '/'))
			{
				input_stream . get ();
				this -> authority = getAuthorityPart
				(
					std::forward <InputStream> (input_stream)
				);
			}
			else
			{
				this -> path . push_back ('/');
			}

			this -> path . append
			(
				getPathPart (std::forward <InputStream> (input_stream))
			);
		}
	}
	else
	{
		this -> path = first_part;
		this -> path . append
		(
			getPathPart (std::forward <InputStream> (input_stream))
		);
	}

	if (IO::Util::test (std::forward <InputStream> (input_stream), '?'))
	{
		input_stream . get ();
		this -> query = getQueryPart
		(
			std::forward <InputStream> (input_stream)
		);
	}

	if (IO::Util::test (std::forward <InputStream> (input_stream), '#'))
	{
		input_stream . get ();
		this -> fragment = getFragmentPart
		(
			std::forward <InputStream> (input_stream)
		);
	}
}
