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
	int read_file_descriptor;
	int write_file_descriptor;
};
