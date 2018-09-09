struct T : std::exception
{
	T (const std::string & message);

	const char *
	what () const noexcept override;

	T &
	set (const std::string & message);

	~T () = default;

	std::string message;
};
