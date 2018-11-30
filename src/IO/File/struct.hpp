struct T : Interface::NonblockingByteBlock::T
{
	T (const std::string & filename, const std::string & mode);

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = delete;

	void
	reset () override;

	off_t
	size () override;

	FileDescriptor::InputStream::T &
	inputStream () override;

	FileDescriptor::OutputStream::T &
	outputStream () override;

	~T () override;

	private:
	private:
	static int
	newFile (const std::string & filename, const std::string & mode);

	int file_descriptor;

	FileDescriptor::InputStream::T input_stream;
	FileDescriptor::OutputStream::T output_stream;
};
