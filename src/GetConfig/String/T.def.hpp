T::T (const InterfaceType & value) : value (value)
{
}

template <typename InputStream>
T::T (InputStream && input_stream)
{
	IO::Util::expect (std::forward <InputStream> (input_stream), '"');
	while (true)
	{
		char c = input_stream . get ();

		if (c == '\\')
		{
			this -> value . push_back (input_stream . get ());
		}
		else if (c == '"')
		{
			return;
		}
		else
		{
			this -> value . push_back (c);
		}
	}
}
