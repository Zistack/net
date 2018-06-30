std::string
getQuery (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	try
	{
		std::string query;

		while (true)
		{
			char c = input_stream -> peek ();

			if (Class::unreserved (c)) query.push_back (input_stream -> get ());
			else if (c == '%') query.push_back (getEscape (input_stream));
			else return query;
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
