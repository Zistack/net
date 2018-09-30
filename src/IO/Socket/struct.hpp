struct T
{
	T (const char * hostname,
	    const char * port,
	    Interface::OutputStream::T * log);
	T (ServerSocket::T * server_socket);

	T (const T & other) = delete;

	void
	shutdown (Direction::T direction);

	~T ();

	int file_descriptor;

	FileDescriptor::InputStream::T * input_stream;
	FileDescriptor::OutputStream::T * output_stream;
};
