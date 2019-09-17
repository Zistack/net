struct T
{
	template <typename Function, typename ... Arguments>
	T (Function && function, Arguments && ... arguments);

	std::thread::id
	id () const;

	void
	join ();

	~T () = default;

private:

	std::thread m_thread;
};
