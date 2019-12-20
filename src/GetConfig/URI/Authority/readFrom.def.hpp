template <typename InputStream>
T::Value
T::readFrom (InputStream && input_stream)
{
	return ::URI::Authority::T (std::forward <InputStream> (input_stream));
}
