struct T : Pipeline::T <Stage::T>
{
	T (const Config::T & config, size_t entity_size);

	void
	addStage (const Header::TransferEncoding::Specification::T & specification);

	void
	addLastStage
	(
		const Header::TransferEncoding::Specification::T & specification,
		size_t chunk_size
	);

	template <typename OutputStream, typename CancellableSlot>
	void
	encode
	(
		const Entity::T & entity,
		OutputStream && output_stream,
		CancellableSlot & encode_slot
	) const;

	~T () = default;
};
