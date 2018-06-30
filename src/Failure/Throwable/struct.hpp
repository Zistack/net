struct T : std::exception
{
	T (std::string message);

	const char * what () const override;

	T& set (std::string message);

	~T () = default;

	std::string message;
};
