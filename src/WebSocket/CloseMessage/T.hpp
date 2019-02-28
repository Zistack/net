T::T (Masking::InputStream::T & input_stream, uint64_t count)
{
	if (count == 0)
	{
		this -> status_code = 1005;
	}
	else if (count >= sizeof (this -> status_code))
	{
		this -> status_code = IO::Rule::getIntType <decltype (this -> status_code)> (input_stream);

		if (count > sizeof (this -> status_code))
		{
			this -> reason . emplace ();

			Util::transfer
			(
				input_stream,
				count - sizeof (this -> status_code),
				this -> reason -> outputStream ()
			);

			this -> reason -> reset ();
		}
	}
	else
	{
		throw Failure::SemanticError::T ("Nonzero payloads on close frames must be at least " + std::to_string (sizeof (this -> status_code)) + " bytes long\n");
	}
}

T::T (uint16_t status_code, const NullableString::T & reason) : status_code (status_code), reason (reason)
{
}
