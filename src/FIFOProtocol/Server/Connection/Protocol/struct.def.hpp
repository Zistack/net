template <typename Interface, typename Request, typename Response>
struct T
:	private InputOutputInterface::T
	<
		Interface,
		T <Interface, Request, Response>,
		Request,
		Response
	>
{
	T () = default;

	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

	~T () = default;
};

static_assert
(
	IO::TypeTraits::IsProtocol::T
	<
		T
		<
			TypeTraits::Interface::T <std::monostate, std::monostate>,
			std::monostate,
			std::monostate
		>
	>::value
);
