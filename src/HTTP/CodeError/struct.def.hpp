struct T : std::exception
{
	T
	(
		uint64_t error_code,
		const std::string & message,
		const HeaderMap::T & headers = {}
	);

	uint64_t
	errorCode () const noexcept;

	const char *
	what () const noexcept override;

	Response::T
	toResponse (uint64_t temp_file_threshhold) const;

	~T () = default;

private:

	uint64_t m_error_code;
	std::string m_message;
	HeaderMap::T m_headers;
};
