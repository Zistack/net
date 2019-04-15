template <typename Dispatcher>
struct T
{
	template <typename ... Arguments>
	T
	(
		std::chrono::milliseconds input_timeout,
		std::chrono::milliseconds close_timeout,
		uint64_t temp_file_threshhold,
		Output::T & output,
		Arguments && ... arguments
	);

	void
	prime ();

	template <typename InputStream>
	void
	run (InputStream && input_stream);

	void
	cancel ();

	~T () = default;

private:

	template <typename InputStream>
	void
	processFrames (InputStream && input_stream);

	template <typename InputStream>
	void
	processEvent (InputStream && input_stream);

	template <typename InputStream>
	void
	waitForCloseFrame (InputStream && input_stream);

	template <typename InputStream>
	void
	waitEvent (InputStream && input_stream);

	template <typename InputStream>
	void
	readPing (const FrameHeader::T & frame_header, InputStream && input_stream);

	template <typename InputStream>
	void
	readPong (const FrameHeader::T & frame_header, InputStream && input_stream);

	template <typename InputStream>
	void
	readMessage
	(
		const FrameHeader::T & frame_header,
		InputStream && input_stream,
		InputEntitySlot::T & entity_slot
	);

	template <typename InputStream>
	void
	readContinuation
	(
		const FrameHeader::T & frame_header,
		InputStream && input_stream,
		InputEntitySlot::T & entity_slot
	);

	template <typename InputStream>
	void
	readClose
	(
		const FrameHeader::T & frame_header,
		InputStream && input_stream
	);

	void
	finalizeMessage ();

	// Given members

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds close_timeout;

	uint64_t temp_file_threshhold;

	Output::T & output;

	Dispatcher dispatcher;

	// Internal members

	Failure::ExceptionStore::T exception_store;

	ShutdownSignal::T input_shutdown_signal;

	std::optional <Message::T> message;
	std::optional <CloseMessage::T> close_message;

	// Transient members

	SuppressingScope::T <ShutdownSignal::T> input_shutdown_scope;
};

static_assert
(
	Failure::TypeTraits::IsCancellable::T <T <TypeTraits::Dispatcher::T>>::value
);
