struct T
{
	T (IO::Interface::InputStream::T <char> * input_stream);

	T (std::string status_code,
		URI::T uri,
		std::string version,
		Headers::T headers,
		Entity::T * entity);

	void
	writeTo (IO::Interface::OutputStream::T <char> * output_stream);

	~T ();

	std::string status_code;
	URI::T uri;
	std::string version;

	Message::Headers::T headers;

	Entity::T * entity;
};
