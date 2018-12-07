template <class Function>
bool
T::start (Function && function, Failure::Cancellable::T * cancellable) noexcept
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (this->cancelled) return false;

	if (this->exception_store) return false;

	Thread::T thread (std::forward<Function> (function), cancellable);

	this->threads.insert ({thread.id (), std::move (thread)});

	return true;
}
