template <typename ServerProtocol>
T <ServerProtocol>::T (ServerProtocol server_protocol, Config::T & config)
:	m_server_protocol (server_protocol),
	m_config (config),
	m_ciphers (this -> m_config . cipherString ())
{
}
