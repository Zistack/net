template <typename InputStream>
T::Value
T::readFrom (InputStream && input_stream)
{
	return ::URI::Rule::getQuery (std::forward <InputStream> (input_stream));
}
