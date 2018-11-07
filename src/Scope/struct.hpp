template <class Scopable>
struct T
{
	T ();

	T (Scopable & scopable);

	T (const T & other) = delete;

	T (T && other);

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other);

	~T ();

	private:
	Scopable * scopable;
};
