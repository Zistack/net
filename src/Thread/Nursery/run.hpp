template <class Function, class Cancel>
void
T::run (Function && function, Cancel && cancel) noexcept
{
	if (this->start (nullptr, std::forward<Cancel> (cancel)))
	{
		bool first_fail = this->exception_store.tryStore (function);
		this->finish ();
		if (first_fail) this->cancel ();
	}
}
