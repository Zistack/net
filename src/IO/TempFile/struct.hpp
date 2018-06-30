struct T
{
	T ();

	void reset ();
	off_t size ();

	~T ();

	char * name;
	int fd;

	FileDescriptor::InputStream::T * input_stream;
	FileDescriptor::OutputStream::T * output_stream;
};
