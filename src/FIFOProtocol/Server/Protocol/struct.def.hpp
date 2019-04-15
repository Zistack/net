template
<
	typename Request,
	typename Response,
	typename Interface,
	typename ... Arguments
>
struct T
{
	T (Arguments ... arguments);

	std::unique_ptr <Connection::Protocol::T <Request, Response, Interface>>
	make ();

	~T () = default;

private:

	std::tuple <Arguments ...> arguments;
};

static_assert
(
	IO::
		TypeTraits::
		IsServerProtocol::
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
