template <class Callable>
struct T;

template <class Return, class... Args>
struct T<Return (*) (Args...)>
{
	using Type = Return;
};

template <class Return, class... Args>
struct T<Return (Args...)>
{
	using Type = Return;
};
