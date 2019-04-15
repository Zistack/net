struct T
{
	T ();

	template <typename InputStream>
	T (InputStream && input_stream);

	T
	(
		bool final_frame,
		bool reserved_1,
		bool reserved_2,
		bool reserved_3,
		Type::T opcode,
		uint64_t payload_length
	);

	T
	(
		bool final_frame,
		bool reserved_1,
		bool reserved_2,
		bool reserved_3,
		Type::T opcode,
		uint64_t payload_length,
		std::array <uint8_t, 4> masking_key
	);

	bool
	isControl () const;

	bool
	isMessage () const;

	void
	validate (bool partial_message) const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	~T () = default;

	// One wonders if we should actually replace this with a byte and some
	// accessors.
	bool final_frame;
	bool reserved_1;
	bool reserved_2;
	bool reserved_3;
	Type::T opcode;

	bool use_mask;
	uint64_t payload_length;

	std::array <uint8_t, 4> masking_key;
};
