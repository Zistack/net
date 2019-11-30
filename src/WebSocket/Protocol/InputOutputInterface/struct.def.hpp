template <typename Interface>
struct T : Input::T <T <Interface>>, Output::T
{
	T (const Config::T & config);

	void
	pongOutput (const std::vector <uint8_t> & payload);

	void
	cancelOutput ();

	void
	dispatch (Message::T && message);

	void
	pong (std::vector <uint8_t> && payload);

	~T () = default;

private:

	const Interface &
	interface () const;

	Interface &
	interface ();
};
