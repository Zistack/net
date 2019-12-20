template <typename InputStream>
T::Value
T::readFrom (InputStream && input_stream)
{
	return ::URI::Rule::getFragment (std::forward <InputStream> (input_stream));
}
