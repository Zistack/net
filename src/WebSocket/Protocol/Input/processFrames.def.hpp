template <typename Dispatcher>
template <typename InputStream>
void
T <Dispatcher>::processFrames (InputStream && input_stream)
{
	IO::Util::eventLoop
	(
		this -> exception_store,
		std::forward <InputStream> (input_stream),
		this -> input_shutdown_signal,
		& T::processEvent <InputStream>,
		this,
		std::forward <InputStream> (input_stream)
	);
}
