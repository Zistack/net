template <class Function, class... Arguments>
void
T::add (Function && function,
    Arguments &&... arguments,
    Failure::Cancellable::T * cancellable) noexcept
{
	this->start (&T::execute,
	    this,
	    std::forward<Function> (function),
	    std::forward<Arguments> (arguments)...,
	    cancellable);
}
