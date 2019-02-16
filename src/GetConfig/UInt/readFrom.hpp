std::unique_ptr<Member::Value::T>
T::readFrom (IO::Interface::PeekableInputStream::T & input_stream) const
{
	return std::make_unique<ValueType> (input_stream);
}
