struct T
{
	T (std::string hostname, std::string port, OutputStream::T <char> * log);
	T (int fd);

	void shutdown (Direction::T direction);

	~T ();

	FileDescriptor::InputStream::T * input_stream;
	FileDescriptor::OutputStream::T * output_stream;
	int fd;
};
