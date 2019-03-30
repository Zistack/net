template <class Rep, class Period, class Callback, class ... CallbackArgs>
T::T
(
	std::chrono::duration <Rep, Period> timeout,
	Callback && callback,
	CallbackArgs && ... callback_args
)
:	stop (false),
	thread
	(
		& T::run <Rep, Period>,
		* this,
		timeout,
		std::forward <Callback> (callback),
		std::forward <CallbackArgs> (callback_args) ...
	)
{
}
