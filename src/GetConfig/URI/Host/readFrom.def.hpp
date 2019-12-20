template <typename InputStream>
T::Value
T::readFrom (InputStream && input_stream)
{
	return ::URI::Authority::Rule::getHost
	(
		std::forward <InputStream> (input_stream)
	);
}
