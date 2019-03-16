template <typename Cancellable, typename Function, typename... Arguments>
bool
T::start (Cancellable * cancellable,
    Function && function,
    Arguments &&... arguments) noexcept
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (this->cancelled) return false;

	if (this->exception_store) return false;

	Thread::T thread (std::forward<Function> (function),
	    std::forward<Arguments> (arguments)...,
	    cancellable);

	this->threads.insert ({thread.id (), std::move (thread)});

	return true;
}
