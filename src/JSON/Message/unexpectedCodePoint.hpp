std::string
unexpectedCodePoint (uint16_t code_point, std::string expected = "")
{
	std::string message = "Unexpected code point: " +
		Util::codePointToHex (code_point) +
		"\n";

	if (! expected.empty ()) message += "Expected " + expected + "\n";

	return message;
}
