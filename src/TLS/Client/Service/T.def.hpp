template <typename Protocol>
template <typename ... ProtocolArguments, typename>
T <Protocol>::T
(
	Config::T & config,
	ProtocolArguments && ... protocol_arguments
)
:	Protocol (std::forward <ProtocolArguments> (protocol_arguments) ...),
	m_config (config),
	m_ciphers (this -> m_config . cipherString ())
{
}
