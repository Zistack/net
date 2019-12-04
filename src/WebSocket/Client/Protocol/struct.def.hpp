template <typename Interface>
struct T : WebSocket::Protocol::T <Interface>
{
	using RequestFactory = RequestFactory::T;

	T
	(
		const RequestFactory & request_factory,
		const HTTP::Response::T & response,
		const Config::T & config
	);

	~T () = default;
};
