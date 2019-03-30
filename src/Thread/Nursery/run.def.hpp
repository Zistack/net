template
<
	typename Cancellable,
	typename Function,
	typename ... Arguments,
	typename
>
void
T::run
(
	Cancellable & cancellable,
	Function && function,
	Arguments && ... arguments
) noexcept
{
	this->run
	(
		& cancellable,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}

template <typename Function, typename ... Arguments, typename>
void
T::run (Function && function, Arguments && ... arguments) noexcept
{
	this->run
	(
		nullptr,
		std::forward<Function> (function),
		std::forward<Arguments> (arguments) ...
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
T::run
(
	Cancellable * cancellable,
	Function && function,
	Arguments && ... arguments
) noexcept
{
	if (this -> start (cancellable, nullptr))
	{
		this -> execute
		(
			std::forward <Function> (function),
			std::forward <Arguments> (arguments) ...
		);
	}
}
