Headers::T
getHeaders (
	IO::Interface::PeekableInputStream::T <char> * filtered_input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getHeaders\n";

	try
	{
		Headers::T headers;

		while (! IO::Util::test (filtered_input_stream, '\n'))
		{
			headers.insert (getHeader (filtered_input_stream));
		}

		return headers;
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
