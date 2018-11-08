template <class Function, class Cancel>
void
T::add (Function && function, Cancel && cancel) noexcept
{
	this->start (
	    [this, function (std::forward<Function> (function))]() mutable {
		    bool first_fail = this->exception_store.tryStore (function);
		    this->finish ();
		    if (first_fail) this->cancel ();
	    },
	    std::forward<Cancel> (cancel));
}
