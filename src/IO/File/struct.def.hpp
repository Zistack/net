struct T
{
	T ();

	T (const std::string & filename, const std::string & mode);

	T (const T & other) = delete;

	T (T && other);

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other);

	operator bool () const;

	off_t
	size () const;

	FileDescriptor::Reader::T
	reader () const;

	FileDescriptor::Reader::T
	readerAt (off_t position) const;

	FileDescriptor::Writer::T
	writer ();

	FileDescriptor::Writer::T
	writerAt (off_t position);

	~T ();

private:

	int m_file_descriptor;
};
