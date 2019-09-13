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
:	m_stop (false),
	m_thread
	(
		& T::run <Rep, Period>,
		* this,
		timeout,
		std::forward <Callback> (callback),
		std::forward <CallbackArgs> (callback_args) ...
	)
{
}
