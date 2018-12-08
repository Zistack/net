struct T
{
	T ();

	T (CancelScope::T & cancel_scope, Cancellable::T & cancellable);

	T (const T & other) = delete;

	T (T && other);

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other);

	void
	reset ();

	~T ();

	private:
	CancelScope::T * cancel_scope;
	Cancellable::T * cancellable;
};
