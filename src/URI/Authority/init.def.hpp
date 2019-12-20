template <typename InputStream>
void
T::init (InputStream && input_stream)
{
	std::string first_part =
		Rule::getFirstPart (std::forward <InputStream> (input_stream));
	IO::String::Reader::T first_part_reader (first_part);

	if (IO::Util::test (std::forward <InputStream> (input_stream), '@'))
	{
		input_stream . get ();

		this -> user_info = Rule::getUserInfo (first_part_reader);
		IO::Util::expectEOF (first_part_reader);

		this -> initHostAndPort (std::forward <InputStream> (input_stream));
	}
	else
	{
		this -> initHostAndPort
		(
			std::forward <InputStream> (first_part_reader)
		);
		IO::Util::expectEOF (first_part_reader);
	}
}
