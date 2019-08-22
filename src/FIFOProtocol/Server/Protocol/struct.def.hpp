template
<
	typename Request,
	typename Response,
	typename Details,
	typename ... Arguments
>
struct T
{
	T (Arguments ... arguments);

	std::unique_ptr <Connection::Protocol::T <Request, Response, Details>>
	make ();

	~T () = default;

private:

	std::tuple <Arguments ...> m_arguments;
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
				TypeTraits::ServerDetails::T <std::monostate, std::monostate>
			>
		>::
		value
);
