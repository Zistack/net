struct T
{
	T ();

protected:

	T (int file_descriptor);

public:

	T (const T & other) = delete;

	T (T && other);

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other);

	IO::FileDescriptor::Reciever::T
	reciever () const;

	IO::FileDescriptor::Sender::T
	sender () const;

	~T ();

private:

	int file_descriptor;
};
