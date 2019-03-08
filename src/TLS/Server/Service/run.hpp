template <typename ServerProtocol>
void
T<ServerProtocol>::run ()
{
	{
		SuppressingScope::T<Shutdown::Signal::T> shutdown_scope (
		    std::move (this->shutdown_scope));

		Thread::Nursery::T nursery (this->exception_store);

		nursery.run (this->shutdown_signal, [this, &nursery]() {
			this->listen (nursery);
			nursery.cancel ();
		});
	}

	this->exception_store.pop ();
}
