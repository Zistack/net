template <typename Function, typename ... Arguments, typename Cancellable>
T::T
(
	Function && function,
	Arguments && ... arguments,
	Cancellable * cancellable
) noexcept
{
	if constexpr (Failure::TypeTraits::IsCancellable::T <T>::value)
	{
		this -> m_cancellable = cancellable;
		this -> m_cancel_cancellable = & Cancellable::cancel;
	}
	else
	{
		static_assert (std::is_convertible_v <Cancellable, std::nullptr_t>);
	}

	if constexpr (std::is_invocable_v <Function, Arguments ...>)
	{
		this -> m_thread = std::thread
		(
			std::forward <Function> (function),
			std::forward <Arguments> (arguments) ...
		);
	}
	else
	{
		static_assert
		(
			std::is_convertible_v <Function, std::nullptr_t> &&
			(sizeof ... (Arguments) == 0)
		);
	}
}
