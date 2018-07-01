std::string
unexpectedCharacter (char c)
{
	std::string message = "Unexpected character: ";

	if (Class::control (c))
		message += Util::charToHex (c);
	else
		message += c;

	message += '\n';

	return message;
}

std::string
unexpectedCharacter (char c, std::string expected)
{
	return unexpectedCharacter (c) + "Expected: " + expected + "\n";
}

std::string
unexpectedCharacter (char c, char e)
{
	std::string expected;

	if (Class::control (e))
		expected = Util::charToHex (e);
	else
		expected = {e};

	return unexpectedCharacter (c, expected);
}

std::string
unexpectedCharacter (char16_t c)
{
	std::string message = "Unexpected character: ";

	if (Class::control (c) || !Class::basicMultilingualPlane (c))
	{
		message += Util::charToHex (c);
	}
	else
		message += Util::runeToUTF8CodePoint ((char32_t) c);

	message += '\n';

	return message;
}

std::string
unexpectedCharacter (char16_t c, std::string expected)
{
	return unexpectedCharacter (c) + "Expected: " + expected + "\n";
}

std::string
unexpectedCharacter (char16_t c, char16_t e)
{
	std::string expected;

	if (Class::control (e) || !Class::basicMultilingualPlane (e))
	{
		expected += Util::charToHex (e);
	}
	else
		expected += Util::runeToUTF8CodePoint ((char32_t) e);

	return unexpectedCharacter (c, expected);
}

std::string
unexpectedCharacter (char32_t c)
{
	std::string message = "Unexpected character: ";

	if (Class::control (c) ||
	    !(Class::basicMultilingualPlane (c) || Class::supplementaryPlane (c)))
	{
		message += Util::charToHex (c);
	}
	else
		message += Util::runeToUTF8CodePoint (c);

	message += '\n';

	return message;
}

std::string
unexpectedCharacter (char32_t c, std::string expected)
{
	return unexpectedCharacter (c) + "Expected: " + expected + "\n";
}

std::string
unexpectedCharacter (char32_t c, char32_t e)
{
	std::string expected;

	if (Class::control (e) ||
	    !(Class::basicMultilingualPlane (e) || Class::supplementaryPlane (e)))
	{
		expected += Util::charToHex (e);
	}
	else
		expected += Util::runeToUTF8CodePoint (e);

	return unexpectedCharacter (c, expected);
}
