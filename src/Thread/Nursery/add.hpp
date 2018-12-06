template <class Function>
void
T::add (Function && function, Failure::Cancellable::T * cancellable) noexcept
{
	this->start (
	    [this, function (std::forward<Function> (function))]() mutable {
		    bool first_fail = this->exception_store.tryStore (function);
		    this->finish ();
		    if (first_fail) this->cancel ();
	    },
	    cancellable);
}
