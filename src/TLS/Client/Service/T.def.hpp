template <typename Protocol>
T <Protocol>::T (Protocol protocol, Config::T & config)
:	m_protocol (protocol),
	m_config (config),
	m_ciphers (this -> m_config . cipherString ())
{
}
