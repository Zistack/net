template <class Function, class Cancel>
bool
T::start (Function && function, Cancel && cancel) noexcept
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (this->exception_store) return false;

	Thread::T thread (
	    std::forward<Function> (function), std::forward<Cancel> (cancel));

	this->threads.insert ({thread.id (), std::move (thread)});

	return true;
}
