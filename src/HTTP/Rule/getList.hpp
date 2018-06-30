std::list <std::string>
getList (IO::Interface::PeekableInputStream::T <char> * filtered_input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getList\n";

	try
	{
		Util::skipWhitespace (filtered_input_stream);

		std::list <std::string> tokens;

		while (true)
		{
			if (IO::Util::test (filtered_input_stream, ','))
			{
				filtered_input_stream -> get ();
				continue;
			}

			std::string token = getToken (filtered_input_stream);

			IO::Util::expect (filtered_input_stream, ',');
		}
	}
	catch (IO::EOF::T) return tokens;
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
