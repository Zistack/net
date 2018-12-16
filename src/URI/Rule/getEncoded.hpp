char
getEncoded (IO::Interface::PeekableInputStream::T & input_stream)
{
	std::string hex;

	IO::Util::expect (input_stream, "%");

	hex.push_back (IO::Util::expect (input_stream, IO::Class::hex));
	hex.push_back (IO::Util::expect (input_stream, IO::Class::hex));

	return (char) std::stoul (hex, 0, 16);
}
