template <typename InputStream>
void
T::init (InputStream && input_stream)
{
	if (IO::Util::test (std::forward <InputStream> (input_stream), '/'))
	{
		this -> m_absolute = true;
		input_stream . get ();
	}
	else
	{
		this -> m_absolute = false;
	}

	std::string segment = Rule::getSegment
	(
		std::forward <InputStream> (input_stream)
	);

	if (segment != "." && segment != "..")
	{
		this -> m_segments . push_back (segment);
	}

	while (IO::Util::test (std::forward <InputStream> (input_stream), '/'))
	{
		input_stream . get ();
		segment = Rule::getSegment (std::forward <InputStream> (input_stream));

		if (segment == ".")
		{
			continue;
		}
		else if (segment == "..")
		{
			if (this -> m_segments . size ()) this -> m_segments . pop_back ();
		}
		else
		{
			this -> m_segments . push_back (segment);
		}
	}
}
