std::string
unexpectedRune (uint32_t rune, std::string expected = "")
{
	std::string message = "Unexpected rune: " + Util::runeToHex (rune) + "\n";

	if (! expected.empty ()) message += "Expected " + expected + "\n";

	return message;
}
