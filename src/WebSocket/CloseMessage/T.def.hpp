template <typename InputStream>
T::T (InputStream && input_stream, uint64_t count)
{
	if (count == 0)
	{
		this -> m_status_code = 1005;
	}
	else if (count >= sizeof (this -> m_status_code))
	{
		this -> m_status_code =
			IO::Rule::getIntType <decltype (this -> m_status_code)>
			(
				std::forward <InputStream> (input_stream)
			);

		if (count > sizeof (this -> m_status_code))
		{
			this -> m_reason = "";
			IO::String::Reader::T output_stream
			(
				this -> m_reason . stdString ()
			);

			Util::transfer
			(
				std::forward <InputStream> (input_stream),
				count - sizeof (this -> m_status_code),
				output_stream
			);
		}
	}
	else
	{
		throw Failure::SemanticError::T
		(
			"Nonzero payloads on close frames must be at least " +
				std::to_string (sizeof (this -> m_status_code)) +
				" bytes long\n"
		);
	}
}

T::T (uint16_t status_code, const NullableString::T & reason)
:	m_status_code (status_code), m_reason (reason)
{
	if (reason && (reason . size () > (125 - sizeof (this -> m_status_code))))
	{
		this -> m_status_code = 1008;
		this -> m_reason = nullptr;
	}
}
