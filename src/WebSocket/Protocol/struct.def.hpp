template <typename Dispatcher>
struct T
{
	template <typename ... Arguments>
	T (const Config::T & config, Arguments && ... arguments);

	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

	void
	send (Message::T && message);

	void
	ping (const std::vector <uint8_t> & payload);

	void
	pong (const std::vector <uint8_t> & payload);

	~T () = default;

private:

	Input::T <Dispatcher> input;
	Output::T output;
};

static_assert
(
	IO::TypeTraits::IsProtocol::T <T <TypeTraits::Dispatcher::T>>::value
);
