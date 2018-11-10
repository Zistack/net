struct T
{
	T ();

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = delete;

	void
	shutdown ();

	FileDescriptor::InputStream::T &
	inputStream ();

	FileDescriptor::OutputStream::T &
	outputStream ();

	~T ();

	private:
	T (std::pair<int, int> pipe_file_descriptors);

	T (int read_file_descriptor, int write_file_descriptor);

	static std::pair<int, int>
	newPipe ();

	int read_file_descriptor;
	int write_file_descriptor;

	bool is_shutdown;

	FileDescriptor::InputStream::T input_stream;
	FileDescriptor::OutputStream::T output_stream;
};
