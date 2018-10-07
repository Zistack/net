struct T
{
	T (char * opts);

	char
	get ();

	char
	peek () const;

	void
	reset ();

	~T () = default;

	char * opts;
	char * opt_ptr;
};
