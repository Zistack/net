template <class Function, class... Arguments>
void
T::run (Function && function,
    Arguments &&... arguments,
    Failure::Cancellable::T * cancellable) noexcept
{
	if (this->start (nullptr, cancellable))
	{
		this->execute (std::forward<Function> (function),
		    std::forward<Arguments> (arguments)...);
	}
}
