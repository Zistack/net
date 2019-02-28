struct T : IO::Interface::InputStream::T
{
	T (IO::Interface::InputStream::T & input_stream, std::array <uint8_t, 4> masking_key);

	char
	get () override;

	~T () = default;

private:

	IO::Interface::InputStream::T & input_stream;

	std::array <uint8_t, 4> masking_key;

	unsigned int i;
};
