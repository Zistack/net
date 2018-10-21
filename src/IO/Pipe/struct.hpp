struct T
{
	T ();
	T (const T & other) = delete;

	T &
	operator= (const T & other) = delete;

	void
	shutdown ();

	~T ();

	FileDescriptor::InputStream::T * input_stream;
	FileDescriptor::OutputStream::T * output_stream;

	int read_file_descriptor;
	int write_file_descriptor;
	bool is_shutdown;
};
