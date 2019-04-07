template <typename InputStream>
void
T::getStatusLine (InputStream && input_stream)
{
	this -> version = Rule::getVersion
	(
		std::forward <InputStream> (input_stream)
	);

	IO::Util::expect (std::forward <InputStream> (input_stream), ' ');

	// I could make a rule just for the status code that knows about the 3 digit
	// constraint.
	this -> status_code = IO::Rule::getUInt
	(
		std::forward <InputStream> (input_stream)
	);

	IO::Util::expect (std::forward <InputStream> (input_stream), ' ');

	this -> reason_phrase = Rule::getText
	(
		std::forward <InputStream> (input_stream)
	);

	IO::Util::expect (std::forward <InputStream> (input_stream), "\r\n");
}
