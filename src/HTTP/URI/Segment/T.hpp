T::T (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Segment::T\n";

	try
	{
		name = Rule::getPChars (input_stream);

		while (IO::Util::test (input_stream, ';'))
		{
			input_stream -> get ();

			parameters.push_back (getPChars (input_stream));
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
