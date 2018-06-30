std::string
unexpectedCharacter (char c, std::string expected = "")
{
	std::string message = "Unexpected character: ";

	if (Class::control (c)) message += Util::charToHex (c);
	else message += c;

	message += '\n';

	if (! expected.empty ()) message += "Expected: " + expected + "\n";

	return message;
}

std::string
unexpectedCharacter (char16_t c, std::string expected = "")
{
	std::string message = "Unexpected character: ";

	if (Class::control (c) || ! Class::basicMultilingualPlane (c))
	{
		message += Util::charToHex (c);
	}
	else message += Util::RuneToUTF8CodePoint ((char32_t) c);

	message += '\n';

	if (! expected.empty ()) message += "Expected: " + expected + "\n";

	return message;
}

std::string
unexpectedCharacter (char32_t c, std::string expected = "")
{
	std::string message = "Unexpected character: ";

	if (Class::control (c) ||
		! (Class::basicMultilingualPlane (c) || Class::supplementaryPlane (c)))
	{
		message += Util::charToHex (c);
	}
	else message += Util::RuneToUTF8CodePoint (c);

	message += '\n';

	if (! expected.empty ()) message += "Expected: " + expected + "\n";

	return message;
}
