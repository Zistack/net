struct T
{
	T ();
	T (std::function<void(void)> setCallback,
	    std::function<void(void)> clearCallback);

	void
	set ();

	void
	clear ();

	void
	lock ();

	void
	unlock ();

	bool
	status () const;

	operator bool () const;

	~T () = default;

	private:
	bool state;

	Thread::SleepLock::T sleep_lock;

	std::function<void(void)> setCallback;
	std::function<void(void)> clearCallback;
};
