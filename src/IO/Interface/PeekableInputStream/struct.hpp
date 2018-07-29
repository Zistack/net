struct T : InputStream::T
{
	virtual char
	get () override = 0;

	virtual char
	peek () = 0;

	bool
	eof ();
};
