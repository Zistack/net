template <typename Dispatcher>
template <typename InputStream>
void
T <Dispatcher>::run (InputStream && input_stream)
{
	SuppressingScope::T input_shutdown_scope
	(
		std::move (this -> input_shutdown_scope)
	);

	try
	{
		this -> processFrames (std::forward <InputStream> (input_stream));

		if (! this -> close_message)
		{
			this -> waitForCloseFrame
			(
				std::forward <InputStream> (input_stream)
			);
		}
	}
	catch (...)
	{
		this -> exception_store . store (std::current_exception ());
	}

	this -> exception_store . pop ();
}
