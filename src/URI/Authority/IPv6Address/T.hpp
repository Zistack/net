T::T (IO::Interface::PeekableInputStream::T & input_stream) : hexadecitets ({0})
{
	this->init (input_stream);
}

T::T (const std::string & address_string) : hexadecitets ({0})
{
	IO::Util::consume (address_string,
	    [this](IO::Interface::PeekableInputStream::T & input_stream) {
		    this->init (input_stream);
	    });
}

T::T (const std::array<uint16_t, 8> & hexadecitets) :
    hexadecitets (hexadecitets)
{
}
