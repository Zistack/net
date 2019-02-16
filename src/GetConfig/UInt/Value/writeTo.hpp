void
T::writeTo (IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	IO::Rule::putUInt (this->value, output_stream);
}
