template <class Signature>
struct T;

template <class ReturnType, class... ArgumentTypes>
struct T<ReturnType (ArgumentTypes...)>
{
	virtual ReturnType
	operator() (ArgumentTypes &&... arguments) = 0;

	virtual std::unique_ptr<T>
	clone () const = 0;

	virtual ~T () = default;
};
