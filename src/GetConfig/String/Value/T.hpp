T::T (const std::string & value) : value (value) {}

T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	IO::Util::expect (input_stream, '"');

	while (true)
	{
		char c = input_stream.get ();

		if (c == '\\')
		{
			this->value.push_back (input_stream.get ());
		}
		else if (c == '"')
		{
			break;
		}
		else
		{
			this->value.push_back (c);
		}
	}
}
