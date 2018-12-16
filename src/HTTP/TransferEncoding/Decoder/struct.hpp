struct T : Pipeline::T
{
	T () = default;

	void
	addFirstStage (const Specification::T & specification);

	void
	addStage (const Specification::T & specification);

	void
	decode (IO::Interface::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Entity::T & entity,
	    Failure::CancelScope::T & cancel_scope);

	~T () = default;
};
