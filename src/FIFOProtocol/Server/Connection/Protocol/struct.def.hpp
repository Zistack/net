template <typename Request, typename Response, typename Interface>
struct T
{
	template <typename... Arguments>
	T (Arguments && ... arguments);

	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

	~T () = default;

private:

	Interface interface;

	Input::T <Request, Response, Interface> input;
	Output::T <Response, Interface> output;
};

static_assert
(
	IO::
		TypeTraits::
		IsProtocol::
		T
		<
			T
			<
				std::monostate,
				std::monostate,
				TypeTraits::ServerInterface::T <std::monostate, std::monostate>
			>
		>::
		value
);
