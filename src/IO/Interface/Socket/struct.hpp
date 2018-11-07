struct T
{
	virtual FileDescriptor::InputStream::T &
	inputStream () = 0;

	virtual FileDescriptor::OutputStream::T &
	outputStream () = 0;

	virtual ~T () = default;
};
