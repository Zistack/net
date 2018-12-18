struct T : Host::T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	T (const std::array<uint16_t, 8> & hexadecitets);

	std::string
	toString () const override;

	std::unique_ptr<Host::T>
	clone () const override;

	~T () override = default;

	private:
	static std::vector<uint16_t>
	getHead (IO::Interface::PeekableInputStream::T & input_stream);

	static std::vector<uint16_t>
	getTail (IO::Interface::PeekableInputStream::T & input_stream);

	static std::string
	hexadecitetToString (uint16_t hexadecitet);

	std::array<uint16_t, 8> hexadecitets;
};
