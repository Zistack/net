struct T
{
	T (IO::InputStream::T * input_stream);

	T (std::string scheme,
		std::string host,
		uint64_t port,
		Path::T absolute_path,
		std::string query);

	void writeTo (IO::OutputStream::T * output_stream);

	~T ();

	std::string scheme;
	std::string host;
	uint64_t port;
	Path::T absolute_path;
	std::string query;
};
