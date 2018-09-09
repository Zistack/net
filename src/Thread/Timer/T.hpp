template <class Rep, class Period>
T::T (std::chrono::duration<Rep, Period> timeout,
    std::function<void(void)> callback) :
    stop (false),
    thread (&T::run<Rep, Period>, this, timeout, callback)
{
}
