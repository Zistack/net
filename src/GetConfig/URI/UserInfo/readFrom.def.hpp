template <typename InputStream>
T::Value
T::readFrom (InputStream && input_stream)
{
	return ::URI::Authority::Rule::getUserInfo
	(
		std::forward <InputStream> (input_stream)
	);
}
