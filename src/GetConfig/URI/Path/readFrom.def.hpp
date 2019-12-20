template <typename InputStream>
T::Value
T::readFrom (InputStream && input_stream)
{
	return ::URI::Path::T (std::forward <InputStream> (input_stream));
}
