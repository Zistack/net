template <typename Interface, typename Request, typename Response>
template <typename InputStream>
void
T <Interface, Request, Response>::run (InputStream && input_stream)
{
	{
		SuppressingScope::T input_shutdown_scope
		(
			std::move (this -> m_input_shutdown_scope)
		);

		Thread::Nursery::Collection::T <true> nursery
		(
			this -> m_exception_store
		);

		IO::Util::eventLoop
		(
			this -> m_exception_store,
			std::forward <InputStream> (input_stream),
			this -> m_input_shutdown_signal,
			[&] ()
			{
				this -> event
				(
					std::forward <InputStream> (input_stream),
					nursery
				);
			}
		);
	}

	this -> interface () . cancelOutput ();

	this -> m_exception_store . pop ();
}
