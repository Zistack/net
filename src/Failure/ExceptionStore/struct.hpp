struct T
{
	T ();

	void
	store (std::exception e);

	void
	poll ();

	~T ();

	std::atomic <std::string *> exception_message;
};
