template <typename ServerProtocol>
void
T <ServerProtocol>::run ()
{
	{
		SuppressingScope::T shutdown_scope
		(
			std::move (this -> m_shutdown_scope)
		);

		Thread::Nursery::T nursery (this -> m_exception_store);

		nursery.run
		(
			this -> m_shutdown_signal,
			[this, & nursery] ()
			{
				this -> listen (nursery);
				nursery . cancel ();
			}
		);
	}

	this -> m_exception_store . pop ();
}
