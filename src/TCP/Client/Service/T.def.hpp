template <typename Protocol>
template <typename ... ProtocolArguments, typename>
T <Protocol>::T
(
	const Config::T & config,
	ProtocolArguments && ... protocol_arguments
)
:	Protocol (std::forward <ProtocolArguments> (protocol_arguments) ...),
	m_config (config)
{
}
