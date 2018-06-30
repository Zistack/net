Error::T
deserialize (std::istream * json_stream,
    unsigned int decimal_places,
    mpz_class * value)
{
	Number::T number;

	Error::T ret = Error::NONE;

	Number::deserialize (&number, json_stream);

	if (decimal_places && number.mantissa->size () != decimal_places)
	{
		ret = Error::UNEXPECTED_FORMAT;
		goto error;
	}

	if (number.exponent)
	{
		ret = Error::UNEXPECTED_FORMAT;
		goto error;
	}

	value->set_str (*number.base + *number.mantissa, 10);

error:

	Number::clean (&number);

	return ret;
}
