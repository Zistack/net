struct T
{
	T ();

	T (const T & other) = delete;

	T (T && other);

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other) = delete;

	void
	shutdown ();

	FileDescriptor::Reciever::T
	reciever () const;

	FileDescriptor::Sender::T
	sender () const;

	~T ();

private:

	int m_read_file_descriptor;
	int m_write_file_descriptor;
};
