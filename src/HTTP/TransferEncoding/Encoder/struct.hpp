struct T : Pipeline::T
{
	T (const Config::Value::T & config, size_t entity_size);

	void
	addStage (const Specification::T & specification);

	void
	addLastStage (const Specification::T & specification, size_t chunk_size);

	void
	encode (Entity::T & entity,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & cancel_scope);

	~T () = default;
};
