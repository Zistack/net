struct T
{
	T (IO::Interface::PeekableInputStream::T <char> * filtered_input_stream,
		IO::Interface::PeekableInputStream::T <char> * input_stream);

	T (std::string method,
		URI::T uri,
		std::string version,
		Headers::T headers,
		Entity::T * entity);

	void
	writeTo (IO::Interface::OutputStream::T <char> * output_stream);

	~T ();

	std::string method;
	UTI::T uri;
	std::string version;

	Message::Headers::T headers;

	Entity::T * entity;
};
