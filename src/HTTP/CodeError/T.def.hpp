T::T
(
	uint64_t error_code,
	const std::string & message,
	const HeaderMap::T & headers
)
:	m_error_code (error_code), m_message (message), m_headers (headers)
{
}
