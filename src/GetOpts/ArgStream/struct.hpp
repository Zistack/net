struct T
{
	T (int argc, char ** argv);

	char *
	get ();

	char *
	peek () const;

	void
	reset ();

	~T () = default;

	int argc;
	char ** argv;

	int argi;
	char ** argp;
};
