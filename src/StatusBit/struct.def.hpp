template <typename Lockable>
struct T
{
	T (Lockable & lockable);

	operator bool () const;

	~T () = default;

private:

	void
	open ();

	void
	close ();

	friend Scope::T <T>;

	// Given members

	Lockable & m_lockable;

	// Internal members

	bool m_state;
};
