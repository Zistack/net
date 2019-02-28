struct T : IO::Interface::OutputStream::T
{
	T (IO::Interface::OutputStream::T & output_stream, std::array <uint8_t, 4> masking_key);

	void
	put (char c) override;

	void
	write (const char * buffer, size_t count) override;

	~T () = default;

private:

	IO::Interface::OutputStream::T & output_stream;

	std::array <uint8_t, 4> masking_key;

	unsigned int i;
};
