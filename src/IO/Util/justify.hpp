std::list<std::string>
justify (const std::string & text, size_t columns)
{
	std::string::size_type pointer = 0;
	String::PeekableInputStream::T input_stream (text, pointer);

	std::list<std::string> lines;

	std::string current_line;

	while (true)
	{
		skipWhitespace (input_stream);

		std::string word = Rule::getNotClass (input_stream, Class::whitespace);

		if (word.empty ()) break;

		if (current_line.empty ())
			current_line.append (word);
		else if (current_line.size () + 1 + word.size () < columns))
			{
				current_line.push_back (' ');
				current_line.append (word);
			}
		else
		{
			lines.push_back (current_line);
			current_line = word;
		}
	}

	if (!current_line.empty ()) lines.push_back (current_line);

	return lines;
}
