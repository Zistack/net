template <typename Scopable>
struct T
{
	T ();

	template <typename... Arguments>
	T (Scopable & scopable,
	    Arguments &&... arguments,
	    Failure::ExceptionStore::T & exception_store);

	T (const T & other) = delete;

	T (T && other);

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other);

	~T ();

	private:
	Scopable * scopable;
	Failure::ExceptionStore::T * exception_store;
};
