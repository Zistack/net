struct T : Cancellable::T
{
	T () = default;

	T (const T & other) = delete;

	T &
	operator= (const T & other) = delete;

	template <class Function, class... Arguments>
	void
	run (Function && f,
	    Arguments &&... arguments,
	    Cancellable::T & cancellable);

	void
	cancel () override;

	~T () = default;

	private:
	void
	add (Cancellable::T & cancellable);

	void
	remove (Cancellable::T & cancellable);

	std::mutex m;
	std::unordered_set<Cancellable::T *> members;
};
