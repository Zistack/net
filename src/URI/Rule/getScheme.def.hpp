template <typename InputStream>
std::string
getScheme (InputStream && input_stream)
{
	std::string scheme;

	scheme . push_back
	(
		IO::Util::expect
		(
			std::forward <InputStream> (input_stream),
			IO::Class::alpha
		)
	);

	while
	(
		IO::Util::test (std::forward <InputStream> (input_stream), Class::schar)
	)
	{
		scheme . push_back (input_stream . get ());
	}

	return scheme;
}
