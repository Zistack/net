template
<
	typename Rep,
	typename Period,
	typename Callback,
	typename ... CallbackArgs
>
T::T
(
	std::chrono::duration <Rep, Period> timeout,
	Callback && callback,
	CallbackArgs && ... callback_args
)
:	m_stop (false)
{
	this -> m_thread = std::thread
	(
		& T::run <Rep, Period, Callback, CallbackArgs ...>,
		std::ref (* this),
		timeout,
		TypeTraits::launder <Callback> (callback),
		TypeTraits::launder <CallbackArgs> (callback_args) ...
	);
}
