template <typename Protocol, typename Dispatcher>
struct T
{
	template <typename ... DispatcherArguments>
	T
	(
		std::chrono::nanoseconds input_timeout,
		std::chrono::nanoseconds close_timeout,
		uint64_t temp_file_threshhold,
		const URI::T & requested_resource,
		DispatcherArguments && ... dispatcher_arguments
	);

	void
	prime ();

	template <typename InputStream>
	void
	run (InputStream && input_stream);

	void
	cancel ();

	~T () = default;

protected:

	const T &
	input () const;

	T &
	input ();

private:

	const Output::T <Protocol> &
	output () const;

	Output::T <Protocol> &
	output ();

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

	std::chrono::nanoseconds m_input_timeout;
	std::chrono::nanoseconds m_close_timeout;

	uint64_t m_temp_file_threshhold;

	Dispatcher m_dispatcher;

	// Internal members

	Failure::ExceptionStore::T m_exception_store;

	ShutdownSignal::T m_input_shutdown_signal;

	std::optional <Message::T> m_message;
	std::optional <CloseMessage::T> m_close_message;

	// Transient members

	SuppressingScope::T <ShutdownSignal::T> m_input_shutdown_scope;
};

static_assert
(
	Failure::
		TypeTraits::
		IsCancellable::
		T
		<
			T
			<
				Interface::T <TypeTraits::Dispatcher::T>,
				TypeTraits::Dispatcher::T
			>
		>::
		value
);
