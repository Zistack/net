Error::T
serialize (mpz_class * value,
    unsigned int decimal_places,
    std::ostream * json_stream)
{
	Number::T number;

	number.negative = sgn (*value) < 0;

	std::string string_value = value->get_str (10);

	if (decimal_places)
	{
		std::string base =
		    string_value.substr (0, string_value.size () - decimal_places);
		std::string mantissa =
		    string_value.substr (string_value.size () - decimal_places);

		Number::init (&number, base);
		Number::setMantissa (&number, mantissa);
	}
	else
	{
		Number::init (&number, string_value);
	}

	Error::T ret = Number::serialize (&number, json_stream);

	Number::clean (&number);

	return ret;
}
