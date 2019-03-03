T::T (Masking::InputStream::T & input_stream, uint64_t count)
{
	if (count == 0)
	{
		this->status_code = 1005;
	}
	else if (count >= sizeof (this->status_code))
	{
		this->status_code =
		    IO::Rule::getIntType<decltype (this->status_code)> (input_stream);

		if (count > sizeof (this->status_code))
		{
			this->reason = "";
			std::string::size_type pointer;
			IO::String::OutputStream::T output_stream (
			    this->reason.stdString (), pointer);

			Util::transfer (input_stream,
			    count - sizeof (this->status_code),
			    output_stream);
		}
	}
	else
	{
		throw Failure::SemanticError::T (
		    "Nonzero payloads on close frames must be at least " +
		    std::to_string (sizeof (this->status_code)) + " bytes long\n");
	}
}

// I might want to include logic for handling reasons that are too long.
// There's a generic failure code we could send in that case.
T::T (uint16_t status_code, const NullableString::T & reason) :
    status_code (status_code),
    reason (reason)
{
	if (reason && (reason.size () > (125 - sizeof (this->status_code))))
	{
		this->status_code = 1008;
		this->reason = nullptr;
	}
}
