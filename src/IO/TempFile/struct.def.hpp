struct T
{
	T ();

	T (const std::string & pattern);

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

	FileDescriptor::Writer::T
	writer () const;

	~T ();

	private:
	std::unique_ptr <char []> name;
	int file_descriptor;
};
