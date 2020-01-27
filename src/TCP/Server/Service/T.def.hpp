template <typename ServerProtocol>
template <typename ... ProtocolArguments, typename>
T <ServerProtocol>::T
(
	const Config::T & config,
	ProtocolArguments && ... protocol_arguments
)
:	m_config (config),
	m_server_protocol
	(
		std::forward <ProtocolArguments> (protocol_arguments) ...
	)
{
}
