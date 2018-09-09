struct T : std::exception
{
	const char *
	what () const noexcept override;
};
