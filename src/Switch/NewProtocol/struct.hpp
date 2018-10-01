struct T : std::exception
{
	T (IO::Interface::Protocol::T * new_protocol);

	IO::Interface::Protocol::T *
	protocol () const;

	const char *
	what () const noexcept override;

	~T () = default;

	private:
	IO::Interface::Protocol::T * new_protocol;
};
