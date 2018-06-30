Error::T
serialize (T * number, std::ostream * json_stream)
{
	if (number->negative)
	{
		json_stream->put ('-');
	}

	for (auto c : *number->base)
	{
		json_stream->put (c);
	}

	if (number->mantissa)
	{
		json_stream->put ('.');

		for (auto c : *number->mantissa)
		{
			json_stream->put (c);
		}
	}

	if (number->exponent)
	{
		json_stream->put ('E');

		if (number->exponent_negative)
		{
			json_stream->put ('-');
		}
		else
		{
			json_stream->put ('+');
		}

		for (auto c : *number->exponent)
		{
			json_stream->put (c);
		}
	}

	return Error::NONE;
}
