struct T
{
	T (std::function<void(void)> setCallback = nullptr,
	    std::function<void(void)> clearCallback = nullptr);

	void
	set ();

	void
	clear ();

	void
	lock ();

	void
	unlock ();

	bool
	status ();

	operator bool ();

	~T () = default;

	private:
	bool state;

	std::mutex m;
	std::condition_variable c;
	bool locked;

	std::function<void(void)> setCallback;
	std::function<void(void)> clearCallback;
};
