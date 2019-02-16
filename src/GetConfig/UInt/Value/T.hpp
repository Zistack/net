T::T (const InterfaceType & value) : value (value) {}

T::T (IO::Interface::PeekableInputStream::T & input_stream) :
    value (IO::Rule::getUInt (input_stream))
{
}
