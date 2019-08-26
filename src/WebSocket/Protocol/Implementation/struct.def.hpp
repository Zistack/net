template <typename Dispatcher>
struct T
:	private Input::T <Interface::T <Dispatcher>, Dispatcher>,
	private Output::T <Interface::T <Dispatcher>>
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

	using Output::T <Interface::T <Dispatcher>>::send;
	using Output::T <Interface::T <Dispatcher>>::ping;
	using Output::T <Interface::T <Dispatcher>>::pong;

	~T () = default;

protected:

	// Inherited members shared with submodules

	using Output::T <Interface::T <Dispatcher>>::output;
};

static_assert
(
	IO::TypeTraits::IsProtocol::T <T <TypeTraits::Dispatcher::T>>::value
);
