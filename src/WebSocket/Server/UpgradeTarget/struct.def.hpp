template <typename Dispatcher>
struct T
{
	template <bool upgrade_required, typename ... DispatcherArguments>
	static std::optional
	<
		std::pair
		<
			HTTP::Response::T,
			std::unique_ptr <WebSocket::Protocol::T <Dispatcher>>
		>
	>
	createServerProtocol
	(
		const HTTP::Request::T & request,
		const Config::T & config,
		DispatcherArguments && ... dispatcher_arguments
	);

	static const HTTP::Header::Upgrade::Protocol::T PROTOCOL;
};
