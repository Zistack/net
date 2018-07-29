struct T
{
	T (std::string hostname,
	    std::string port,
	    Interface::OutputStream::T * log);
	T (int file_descriptor);

	void
	shutdown (Direction::T direction);

	~T ();

	int file_descriptor;

	FileDescriptor::InputStream::T input_stream;
	FileDescriptor::OutputStream::T output_stream;
};
