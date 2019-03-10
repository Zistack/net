template <typename InputStream>
void
T::init (InputStream && input_stream)
{
	if (IO::Util::test (std::forward<InputStream> (input_stream), '/'))
	{
		this->absolute = true;
		input_stream.get ();
	}
	else
	{
		this->absolute = false;
	}

	std::string segment =
	    Rule::getSegment (std::forward<InputStream> (input_stream));

	if (segment != "." && segment != "..")
	{
		this->segments.push_back (segment);
	}

	while (IO::Util::test (std::forward<InputStream> (input_stream), '/'))
	{
		input_stream.get ();
		segment = Rule::getSegment (std::forward<InputStream> (input_stream));

		if (segment == ".")
		{
			continue;
		}
		else if (segment == "..")
		{
			if (this->segments.size ()) this->segments.pop_back ();
		}
		else
		{
			this->segments.push_back (segment);
		}
	}
}
