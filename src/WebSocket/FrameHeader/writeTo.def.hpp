template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	uint8_t code_bits = 0;

	code_bits |= this -> final_frame * 0x80;
	code_bits |= this -> reserved_1 * 0x40;
	code_bits |= this -> reserved_2 * 0x20;
	code_bits |= this -> reserved_3 * 0x10;

	code_bits |= this -> opcode;

	output_stream . put ((char) code_bits);

	uint8_t payload_bits = 0;

	payload_bits |= this -> use_mask * 0x80;

	if (this -> payload_length <= 125)
	{
		payload_bits |= this -> payload_length;
		output_stream . put ((char) payload_bits);
	}
	else if (this -> payload_length < 1 << 16)
	{
		payload_bits |= 126;
		output_stream . put ((char) payload_bits);

		IO::Rule::putIntType <uint16_t>
		(
			(uint16_t) this -> payload_length,
			std::forward <OutputStream> (output_stream)
		);
	}
	else
	{
		payload_bits |= 127;
		output_stream . put ((char) payload_bits);

		IO::Rule::putIntType <uint64_t>
		(
			this -> payload_length,
			std::forward <OutputStream> (output_stream)
		);
	}

	if (this -> use_mask)
	{
		for (auto && byte : this -> masking_key)
		{
			output_stream . put ((char) byte);
		}
	}
}
