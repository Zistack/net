template <typename TypeType, typename ValueType>
ValueType
T<TypeType, ValueType>::readFromFile (const std::string & filename,
    std::chrono::milliseconds timeout)
{
	return IO::Util::parseFile (filename,
	    timeout,
	    [](IO::Interface::PeekableInputStream::T & input_stream) {
		    return ValueType (input_stream);
	    });
}
