struct T : Cancellable::T
{
	T ();

	T (const T & other) = delete;

	T &
	operator= (const T & other) = delete;

	void
	cancel () override;

	~T () = default;

	private:
	bool
	add (Cancellable::T & cancellable);

	void
	remove (Cancellable::T & cancellable);

	friend struct Bind::T;

	std::mutex m;
	bool cancelled;

	std::unordered_set<Cancellable::T *> members;
};
