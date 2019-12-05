template <typename Interface>
struct T : Input::T <T <Interface>>, Output::T
{
	T
	(
		std::chrono::nanoseconds input_timeout,
		std::chrono::nanoseconds output_timeout,
		std::chrono::nanoseconds close_timeout,
		uint64_t chunk_size,
		uint64_t temp_file_threshhold
	);

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
