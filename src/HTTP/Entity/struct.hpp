struct T
{
	T ();

	IO::FileDescriptor::InputStream::T * getInputStream ();
	IO::FileDescriptor::OutputStream::T * getOutputStream ();

	void reset ();
	off_t size ();

	~T () = default;

	IO::TempFile::T temp_file;
};
