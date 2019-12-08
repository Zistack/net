template <typename Interface>
template <typename InputStream>
void
T <Interface>::processFrames (InputStream && input_stream)
{
	IO::Util::eventLoop
	(
		this -> m_exception_store,
		std::forward <InputStream> (input_stream),
		this -> m_input_shutdown_signal,
		[&] ()
		{
			this -> processEvent (std::forward <InputStream> (input_stream));
		}
	);
}
