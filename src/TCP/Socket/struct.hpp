struct T : IO::Interface::Socket::T
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
	inputStream () override;
	IO::FileDescriptor::OutputStream::T &
	outputStream () override;

	virtual ~T () override;

	private:
	int file_descriptor;

	IO::FileDescriptor::InputStream::T input_stream;
	IO::FileDescriptor::OutputStream::T output_stream;
};
