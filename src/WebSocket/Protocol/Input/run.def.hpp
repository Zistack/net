template <typename Protocol, typename Dispatcher>
template <typename InputStream>
void
T <Protocol, Dispatcher>::run (InputStream && input_stream)
{
	SuppressingScope::T input_shutdown_scope
	(
		std::move (this -> m_input_shutdown_scope)
	);

	try
	{
		this -> processFrames (std::forward <InputStream> (input_stream));

		if (! this -> m_close_message)
		{
			this -> waitForCloseFrame
			(
				std::forward <InputStream> (input_stream)
			);
		}
	}
	catch (...)
	{
		this -> m_exception_store . store (std::current_exception ());
	}

	this -> m_exception_store . pop ();
}
