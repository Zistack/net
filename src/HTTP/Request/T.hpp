T::T (IO::Interface::PeekableInputStream::T * filtered_input_stream,
	IO::Interface::PeekableInputStream::T * input_stream) :
	entity (NULL)
{
	const std::string message_prefix = "HTTP::Request::T\n";

	try
	{
		method = Rule::getToken (input_stream);

		IO::Util::expect (input_stream, ' ');

		uri = URI::T (input_stream);

		IO::Util::expect (input_stream, ' ');

		version = Rule::getVersion (input_stream);

		IO::Util::expect (input_stream, "\r\n");

		headers = Rule::getHeaders (filtered_input_stream, input_stream);

		IO::Util::expect (input_stream, "\r\n");

		if (Rule::isEntity (& headers))
		{
			EntityInfo entity_info (& headers);

			entity =
				new Entity (& entity_info, filtered_input_stream, input_stream);
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}

T::T (std::string method,
	URI::T uri,
	std::string version,
	Headers::T headers,
	Entity::T * entity) :
	method (method),
	uri (uri),
	version (version),
	headers (headers),
	entity (entity)
{
	if (entity)
	{
		headers.insert ({"Content-Length", std::to_string (entity -> size ())});
	}
}
