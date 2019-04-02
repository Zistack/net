template <typename InputStream>
char
getEncoded (InputStream && input_stream)
{
	std::string hex;

	IO::Util::expect (std::forward <InputStream> (input_stream), "%");

	hex . push_back
	(
		IO::Util::expect
		(
			std::forward <InputStream> (input_stream),
			IO::Class::hex
		)
	);
	hex . push_back
	(
		IO::Util::expect
		(
			std::forward <InputStream> (input_stream),
			IO::Class::hex
		)
	);

	return (char) std::stoul (hex, 0, 16);
}
