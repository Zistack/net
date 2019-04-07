template <typename InputStream>
void
T::getRequestLine (InputStream && input_stream)
{
	this -> method = Rule::getToken (std::forward <InputStream> (input_stream));

	IO::Util::expect (std::forward <InputStream> (input_stream), ' ');

	std::string uri_string = IO::Rule::getNotClass
	(
		std::forward <InputStream> (input_stream),
		' '
	);

	this -> uri = URI::T (uri_string);

	IO::Util::expect (std::forward <InputStream> (input_stream), ' ');

	this -> version = Rule::getVersion
	(
		std::forward <InputStream> (input_stream)
	);

	IO::Util::expect (std::forward <InputStream> (input_stream), "\r\n");
}
