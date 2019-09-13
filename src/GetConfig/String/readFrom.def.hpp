template <typename InputStream>
T::Value
T::readFrom (InputStream && input_stream)
{
	Value value;

	IO::Util::expect (std::forward <InputStream> (input_stream), '"');
	while (true)
	{
		char c = input_stream . get ();

		if (c == '\\')
		{
			value . push_back (input_stream . get ());
		}
		else if (c == '"')
		{
			return value;
		}
		else
		{
			value . push_back (c);
		}
	}
}
