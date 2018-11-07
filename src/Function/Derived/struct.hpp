template <class Callable, class ReturnType, class... ArgumentTypes>
struct T : Base::T<ReturnType (ArgumentTypes...)>
{
	T () = delete;

	T (const T & other) = delete;

	T (T && other) = delete;

	T (const Callable & callable);

	T (Callable && callable);

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = delete;

	ReturnType
	operator() (ArgumentTypes &&... arguments) override;

	std::unique_ptr<Base::T<ReturnType (ArgumentTypes...)>>
	clone () const override;

	~T () override = default;

	private:
	Callable callable;

	friend struct Clone::T<Callable,
	    std::is_copy_constructible<Callable>::value,
	    ReturnType,
	    ArgumentTypes...>;
};
