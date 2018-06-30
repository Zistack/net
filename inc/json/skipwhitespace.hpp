void
skipWhitespace (std::istream * json_stream)
{
	std::char_traits<char>::int_type c;

	do
	{
		c = json_stream->peek ();

		if (whitespace (c))
		{
			json_stream->get ();
			continue;
		}
		else
			return;
	} while (true);
}
