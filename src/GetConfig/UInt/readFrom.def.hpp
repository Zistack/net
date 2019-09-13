template <typename InputStream>
T::Value
T::readFrom (InputStream && input_stream)
{
	return IO::Rule::getUInt (std::forward <InputStream> (input_stream));
}
