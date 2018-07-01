struct T
{
	T (const std::string & pattern);

	void
	reset ();
	off_t
	size ();

	~T ();

	char * name;
	int file_descriptor;

	FileDescriptor::InputStream::T * input_stream;
	FileDescriptor::OutputStream::T * output_stream;
};
