struct T : std::exception
{
	T (std::string message) : message (message) {}
	~T () = default;

	const char *
	what () const noexcept;

	std::string message;
};
