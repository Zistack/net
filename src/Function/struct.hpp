template <class Signature>
struct T;

template <class ReturnType, class... ArgumentTypes>
struct T<ReturnType (ArgumentTypes...)>
{
	T ();

	T (const T & other);

	T (T && other);

	template <class Callable,
	    typename = typename std::enable_if<
	        !std::is_same<T, typename std::decay<Callable>::type>::value>::type,
	    typename = typename std::enable_if<
	        std::is_copy_constructible<Callable>::value>::type>
	T (const Callable & callable);

	template <class Callable,
	    typename = typename std::enable_if<
	        !std::is_same<T, typename std::decay<Callable>::type>::value>::type,
	    typename = typename std::enable_if<
	        std::is_move_constructible<Callable>::value>::type,
	    typename = typename std::enable_if<
	        !std::is_lvalue_reference<Callable>::value>::type>
	T (Callable && callable);

	T &
	operator= (const T & other);

	T &
	operator= (T && other);

	operator bool () const;

	ReturnType
	operator() (ArgumentTypes &&... arguments);

	~T () = default;

	private:
	std::unique_ptr<Base::T<ReturnType (ArgumentTypes...)>> function;
};
