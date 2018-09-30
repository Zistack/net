struct T
{
	T ();

	void
	lock ();

	void
	unlock ();

	~T () = default;

	std::mutex m;
	std::condition_variable c;
	bool locked;
};
