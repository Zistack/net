template <typename Dispatcher>
struct T
{
	T ();

	HTTP::Request::T
	createUpgradeRequest (const URI::T & uri);

	template <typename ... DispatcherArguments>
	std::unique_ptr <WebSocket::Protocol::T <Dispatcher>>
	createClientProtocol
	(
		const HTTP::Response::T & response,
		const Config::T & config,
		DispatcherArguments && ... dispatcher_arguments
	);

	~T () = default;

private:

	std::string m_client_key_base64;
};
