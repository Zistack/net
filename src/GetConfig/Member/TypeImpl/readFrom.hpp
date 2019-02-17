template <typename TypeType, typename ValueType>
std::unique_ptr<Member::Value::T>
T<TypeType, ValueType>::readFrom (
    IO::Interface::PeekableInputStream::T & input_stream) const
{
	return std::make_unique<ValueType> (input_stream);
}
