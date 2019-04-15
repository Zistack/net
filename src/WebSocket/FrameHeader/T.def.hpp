T::T ()
:	final_frame (false),
	reserved_1 (false),
	reserved_2 (false),
	reserved_3 (false),
	opcode (0),
	use_mask (false),
	payload_length (0),
	masking_key ({0})
{
}

template <typename InputStream>
T::T (InputStream && input_stream)
:	payload_length (0), masking_key ({0})
{
	try
	{
		uint8_t code_bits = (uint8_t) input_stream . get ();

		// One wonders if we couldn't just use the byte and pull bools
		// on-demand.
		this -> final_frame = (bool) code_bits & 0x80;
		this -> reserved_1 = (bool) code_bits & 0x40;
		this -> reserved_2 = (bool) code_bits & 0x20;
		this -> reserved_3 = (bool) code_bits & 0x10;

		this -> opcode = code_bits & 0x0F;

		uint8_t payload_bits = (uint8_t) input_stream . get ();

		this -> use_mask = (bool) payload_bits & 0x80;
		payload_bits &= ~ 0x80;

		if (payload_bits == 126)
		{
			payload_length |= (uint64_t) (input_stream . get () << 8);
			payload_length |= (uint64_t) (input_stream . get () << 0);
		}
		else if (payload_bits == 127)
		{
			int i;
			for (i = 7; i >= 0; --i)
			{
				payload_length |= (uint64_t) (input_stream . get () << (i * 8));
			}
		}
		else
		{
			this -> payload_length = payload_bits;
		}

		if (this -> use_mask)
		{
			for (auto & byte : this -> masking_key)
			{
				byte = (uint8_t) input_stream . get ();
			}
		}
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
	}
}

T::T
(
	bool final_frame,
	bool reserved_1,
	bool reserved_2,
	bool reserved_3,
	Type::T opcode,
	uint64_t payload_length
)
:	final_frame (final_frame),
	reserved_1 (reserved_1),
	reserved_2 (reserved_2),
	reserved_3 (reserved_3),
	opcode (opcode),
	use_mask (false),
	payload_length (payload_length),
	masking_key ({0})
{
}

T::T
(
	bool final_frame,
	bool reserved_1,
	bool reserved_2,
	bool reserved_3,
	Type::T opcode,
	uint64_t payload_length,
	std::array <uint8_t, 4> masking_key
)
:	final_frame (final_frame),
	reserved_1 (reserved_1),
	reserved_2 (reserved_2),
	reserved_3 (reserved_3),
	opcode (opcode),
	use_mask (true),
	payload_length (payload_length),
	masking_key (masking_key)
{
}
