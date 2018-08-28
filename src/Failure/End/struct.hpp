struct T : std::exception
{
	T () = default;

	const char *
	what () const noexcept override;

	~T () = default;
};
