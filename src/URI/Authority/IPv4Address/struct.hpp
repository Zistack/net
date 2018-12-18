struct T : Host::T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	T (const std::array<uint8_t, 4> & octets);

	std::string
	toString () const override;

	std::unique_ptr<Host::T>
	clone () const override;

	~T () override = default;

	private:
	std::array<uint8_t, 4> octets;
};
