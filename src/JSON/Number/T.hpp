T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	init (input_stream);
}

T::T (const std::string & number_string)
{
	IO::Util::consume (number_string,
	    [this](IO::Interface::PeekableInputStream::T & input_stream) {
		    this->init (input_stream);
	    });
}
