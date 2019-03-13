template <typename Scopable>
struct T
{
	T ();

	template <typename... Arguments>
	T (Scopable & scopable, Arguments &&... arguments);

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
