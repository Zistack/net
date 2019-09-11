template
<
	typename Cancellable,
	typename Function,
	typename ... Arguments,
	typename
>
void
T::add
(
	Cancellable & cancellable,
	Function && function,
	Arguments && ... arguments
) noexcept
{
	this -> add
	(
		& cancellable,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}

template <typename Function, typename ... Arguments, typename>
void
T::add (Function && function, Arguments && ... arguments) noexcept
{
	this -> add
	(
		nullptr,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}

template
<
	typename Cancellable,
	typename Function,
	typename ... Arguments,
	typename
>
void
T::add
(
	Cancellable * cancellable,
	Function && function,
	Arguments &&... arguments
) noexcept
{
	this -> start
	(
		& T::execute,
		this,
		cancellable,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}
