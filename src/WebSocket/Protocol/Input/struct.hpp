struct T : Failure::Cancellable::T
{
	T (std::chrono::milliseconds input_timeout, std::chrono::milliseconds close_timeout, uint64_t temp_file_threshhold, Output::T & output, Dispatcher::T & dispatcher);

	void
	prime ();

	void
	run (IO::Interface::NonblockingInputStream::T & nonblocking_input_stream);

	void
	cancel () override;

	~T () = default;

	private:

	void
	processFrames (IO::Interface::InputStream::T & input_stream, IO::CancelSignal::T & input_timeout_signal);

	void
	processEvent (IO::Interface::InputStream::T & input_stream, IO::CancelSignal::T & input_timeout_signal);

	void
	waitForCloseFrame (IO::Interface::InputStream::T & input_stream, IO::CancelSignal::T & input_timeout_signal);

	void
	waitEvent (IO::Interface::InputStream::T & input_stream, IO::CancelSignal::T & input_timeout_signal);

	void
	ping (const FrameHeader::T & frame_header, IO::Interface::InputStream::T & input_stream);

	void
	pong (const FrameHeader::T & frame_header, IO::Interface::InputStream::T & input_stream);

	void
	message (const FrameHeader::T & frame_header, IO::Interface::InputStream::T & input_stream, IO::CancelSignal::T & input_timeout_signal);

	void
	continuation (const FrameHeader::T & frame_header, IO::Interface::InputStream::T & input_stream, IO::CancelSignal::T & input_timeout_signal);

	void
	close (const FrameHeader::T & frame_header, IO::Interface::InputStream::T & input_stream);

	std::unique_ptr <HTTP::Entity::T>
	pickEntity (bool final_frame, uint64_t payload_length);

	void
	finalizeMessage (const FrameHeader::T & frame_header);

	// Given members

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds close_timeout;

	uint64_t temp_file_threshhold;

	Output::T & output;
	Dispatcher::T & dispatcher;

	// Internal members

	Failure::ExceptionStore::T exception_store;

	Shutdown::Signal::T input_shutdown_signal;

	std::unique_ptr<Message::T> message;

	std::optional <CloseMessage::T> close_message;

	// Transient members;

	SuppressingScope::T <Shutdown::Signal::T> input_shutdown_scope;
};
