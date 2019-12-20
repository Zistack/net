template <typename InputStream>
void
T::initHostAndPort (InputStream && input_stream)
{
	this -> host = std::move
	(
		Rule::getHost (std::forward <InputStream> (input_stream))
	);

	if (IO::Util::test (std::forward <InputStream> (input_stream), ':'))
	{
		input_stream . get ();

		this -> port = IO::Rule::getUInt
		(
			std::forward <InputStream> (input_stream)
		);
	}
}
