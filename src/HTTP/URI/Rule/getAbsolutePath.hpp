std::list <Segment::T>
getAbsolutePath (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Rule::getAbsolutePath\n";

	try
	{
		std::list <Segment::T> path;

		while (IO::Util::test (input_stream, '/'))
		{
			input_stream -> get ();

			path.push_back (Segment::T (input_stream));
		}

		return path;
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
