struct T
{
	template <typename Function, typename ... Arguments>
	T (Function && function, Arguments && ... arguments);

	T (T && other) = default;

	T &
	operator = (T && other) = default;

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
