struct T : Interface::NonblockingByteBlock::T
{
	T (const std::string & pattern);

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
	T (std::pair<std::unique_ptr<char[]>, int> temp_file);

	T (std::unique_ptr<char[]> && name, int file_descriptor);

	static std::pair<std::unique_ptr<char[]>, int>
	newTempFile (const std::string & pattern);

	std::unique_ptr<char[]> name;
	int file_descriptor;

	FileDescriptor::InputStream::T input_stream;
	FileDescriptor::OutputStream::T output_stream;
};
