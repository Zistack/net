struct T : Pipeline::T <Stage::T>
{
	T ();

	T (uint64_t content_length);

	T (const NullableString::T & transfer_encoding_string, bool is_request);

	template <typename InputStream, typename CancellableSlot>
	void
	decode
	(
		InputStream && input_stream,
		Entity::T & entity,
		CancellableSlot & decode_slot
	) const;

	~T () = default;

private:

	void
	addFirstStage
	(
		const Header::TransferEncoding::Specification::T & specification
	);

	void
	addStage (const Header::TransferEncoding::Specification::T & specification);

	void
	addUnboundedIdentity ();
};
