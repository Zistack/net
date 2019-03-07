template <typename Protocol>
void
T<Protocol>::run ()
{
	{
		SuppressingScope::T<decltype (this->shutdown_signal)> shutdown_scope (
		    std::move (this->shutdown_scope));

		Thread::Nursery::T nursery (this->exception_store);

		nursery.run (this->shutdown_signal, [this, &nursery]() {
			this->listen (nursery);
			nursery.cancel ();
		});
	}

	this->exception_store.pop ();
}
