struct T : Pipeline::T
{
	T () = default;

	void
	addStage (const Specification::T & specification);

	void
	addLastStage (const Specification::T & specification);

	void
	encode (Entity::T & entity,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & cancel_scope);

	~T () = default;
};
