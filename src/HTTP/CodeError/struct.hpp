struct T : std::exception
{
	T (uint64_t error_code, const std::string & message);

	uint64_t
	errorCode () const noexcept;

	const char *
	what () const noexcept override;

	~T () = default;

	private:
	uint64_t error_code;
	std::string message;
};
