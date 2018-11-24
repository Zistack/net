struct T : Interface::WatchableOutputStream::T
{
	template <class... CancelSignals>
	T (Interface::NonblockingOutputStream::T & output_stream,
	    CancelSignals &... cancel_signals);

	T (Interface::NonblockingOutputStream::T & output_stream,
	    std::initializer_list<std::reference_wrapper<Interface::Watchable::T>>
	        cancel_signals);

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = delete;

	void
	put (char c) override;

	void
	write (const char * buffer, size_t count) override;

	Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T () = default;

	Interface::NonblockingOutputStream::T & output_stream;
	std::initializer_list<std::reference_wrapper<Interface::Watchable::T>>
	    cancel_signals;
};
