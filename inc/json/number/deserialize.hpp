void
deserialize (T * number, std::istream * json_stream)
{
	skipWhitespace (json_stream);

	std::char_traits<char>::int_type c;

	bool negative = false;
	std::string * base = NULL;
	std::string * mantissa = NULL;
	bool exponent_negative = false;
	std::string * exponent = NULL;

	// For error handling later.
	bool sign;
	std::string found;
	std::string expected;

	c = json_stream->get ();
	if (c == '-')
	{
		negative = true;
		c = json_stream->get ();
	}

	if (eof (c)) throw SyntaxError::T ("EOF");

	// base:

	base = new std::string ();

	if (c == '0')
	{
		base->push_back ('0');

		c = json_stream->peek ();

		if (terminal (c)) goto done;

		c = json_stream->get ();

		if (c == '.') goto mantissa;
		if (c == 'E' || c == 'e') goto exponent;

		throw SyntaxError::T ({'\'', (char) c, '\''}, "'.' or 'E' or 'e'");
	}

	if (c >= '1' && c <= '9')
	{
		base->push_back ((char) c);

		do
		{
			c = json_stream->peek ();

			if (terminal (c)) goto done;

			c = json_stream->get ();

			if (c == '.') goto mantissa;
			if (c == 'E' || c == 'e') goto exponent;

			if (digit (c))
			{
				base->push_back ((char) c);
				continue;
			}

			throw SyntaxError::T (
			    {'\'', (char) c, '\''}, "digit or '.' or 'E' or 'e'");
		} while (true);
	}

	if (negative) throw SyntaxError::T ({'\'', (char) c, '\''}, "digit");
	throw SyntaxError::T ({'\'', (char) c, '\''}, "digit or '-'");

mantissa:

	mantissa = new std::string ();

	do
	{
		c = json_stream->peek ();

		if (terminal (c)) goto done;

		c = json_stream->get ();

		if (c == 'E' || c == 'e') goto exponent;

		if (digit (c))
		{
			mantissa->push_back ((char) c);
			continue;
		}

		throw SyntaxError::T ({'\'', (char) c, '\''}, "digit or 'E' or 'e'");

	} while (true);

exponent:

	exponent = new std::string ();

	c = json_stream->get ();

	sign = false;

	if (c == '-')
	{
		exponent_negative = true;
		sign = true;
		c = json_stream->get ();
	}
	else if (c == '+')
	{
		sign = true;
		c = json_stream->get ();
	}

	if (digit (c))
	{
		exponent->push_back ((char) c);

		do
		{
			c = json_stream->get ();

			if (terminal (c)) goto done;

			c = json_stream->get ();

			if (digit (c))
			{
				exponent->push_back ((char) c);
				continue;
			}

			throw SyntaxError::T ({'\'', (char) c, '\''}, "digit");
		} while (true);
	}

	if (eof (c))
		found = "EOF";
	else
		found = {'\'', (char) c, '\''};

	if (sign)
		expected = "digit";
	else
		expected = "digit or '+' or '-'";

	throw SyntaxError::T (found, expected);

done:

	number->negative = negative;
	number->base = base;
	number->mantissa = mantissa;
	number->exponent_negative = exponent_negative;
	number->exponent = exponent;
}
