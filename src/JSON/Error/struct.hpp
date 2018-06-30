struct T : public std::exception
{
	T (std::string message);

	~T () = default;

	const char *
	what () const noexcept;

	std::string message;
};
