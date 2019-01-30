struct T
{
	protected:
	T (int file_descriptor);

	public:
	T (const T & other) = delete;
	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;
	T &
	operator= (T && other) = delete;

	IO::FileDescriptor::InputStream::T &
	inputStream ();
	IO::FileDescriptor::OutputStream::T &
	outputStream ();

	~T ();

	private:
	int file_descriptor;

	IO::FileDescriptor::InputStream::T input_stream;
	IO::FileDescriptor::OutputStream::T output_stream;
};
