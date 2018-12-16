struct T
{
	T () = default;

	void
	setBoundedIdentity (size_t size);

	void
	setUnboundedIdentity ();

	void
	recode (IO::Interface::InputStream::T & input_stream,
	    IO::CancelSignal::T * input_cancel_signal,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T * output_cancel_signal,
	    Failure::CancelScope::T & cancel_scope);

	~T () = default;

	protected:
	void
	addStage (std::unique_ptr<Stage::T> && stage);

	private:
	std::list<std::unique_ptr<Stage::T>> stages;
};
