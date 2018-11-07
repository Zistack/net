template <class Lockable>
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

	friend Scope::T<T>;

	// Given members

	Lockable & lockable;

	// Internal members

	bool state;
};
