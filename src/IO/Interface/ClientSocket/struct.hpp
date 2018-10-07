struct T
{
	virtual FileDescriptor::InputStream::T *
	inputStream () const = 0;

	virtual FileDescriptor::OutputStream::T *
	outputStream () const = 0;

	virtual ~T () = default;
};
