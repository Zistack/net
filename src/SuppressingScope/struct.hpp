template <class Scopable>
struct T
{
	T ();

	T (Scopable & scopable, Failure::ExceptionStore::T & exception_store);

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
