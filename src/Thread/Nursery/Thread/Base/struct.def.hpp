struct T
{
	T () = default;

	T (T && other) = default;

	T &
	operator = (T && other) = default;

	template <typename Function, typename ... Arguments>
	void
	run (Function && function, Arguments && ... arguments);

	std::thread::id
	id () const;

	void
	join ();

	void
	detach ();

	~T () = default;

private:

	std::thread m_thread;
};
