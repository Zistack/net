template <class Element,
    Element (IO::Interface::PeekableInputStream::T &) parseElement>
std::list<Element>
getList (IO::Interface::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getList\n";

	std::list<Element> elements;

	try
	{
		while (true)
		{
			if (IO::Util::test (input_stream, ','))
			{
				input_stream.get ();
				Util::skipWhitespace (input_stream);
				continue;
			}

			if (input_stream.eof ()) return elements;

			elements.push_back (parseElement (input_stream));

			Util::skipWhitespace (input_stream);

			if (IO::Util::test (input_stream, ','))
			{
				input_stream.get ();
				Util::skipWhitespace (input_stream);
				continue;
			}
			else
				return elements;
		}
	}
	catch (IO::EOF::T)
	{
		return elements;
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
