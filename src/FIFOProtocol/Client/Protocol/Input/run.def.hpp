template <typename Protocol, typename Response, typename Details>
template <typename InputStream>
void
T <Protocol, Response, Details>::run (InputStream && input_stream)
{
	{
		SuppressingScope::T input_shutdown_scope
		(
			std::move (this -> m_input_shutdown_scope)
		);

		Scope::T response_scope (std::move (this -> m_response_scope));

		IO::Util::eventLoop
		(
			this -> m_exception_store,
			std::forward <InputStream> (input_stream),
			this -> m_input_shutdown_signal,
			[&] ()
			{
				this -> event (std::forward <InputStream> (input_stream));
			}
		);
	}

	this -> m_exception_store . pop ();
}
