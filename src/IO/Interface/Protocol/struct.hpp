struct T
{
	virtual void init (IO::Socket::T * socket) = 0;
	virtual void event () = 0;
	virtual void clean () = 0;
};
