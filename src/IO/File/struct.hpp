struct T
{
	T (const std::string & filename, const std::string & mode);

	T (const T & other) = delete;

	void
	reset ();

	off_t
	size ();

	~T ();

	int file_descriptor;

	FileDescriptor::InputStream::T * input_stream;
	FileDescriptor::OutputStream::T * output_stream;
};
