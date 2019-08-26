template <typename Protocol, typename Dispatcher>
template <typename InputStream>
void
T <Protocol, Dispatcher>::processFrames (InputStream && input_stream)
{
	IO::Util::eventLoop
	(
		this -> m_exception_store,
		std::forward <InputStream> (input_stream),
		this -> m_input_shutdown_signal,
		& T::processEvent <InputStream>,
		this,
		std::forward <InputStream> (input_stream)
	);
}
