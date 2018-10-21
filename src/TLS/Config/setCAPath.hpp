void
T::setCAPath (const std::string & ca_path)
{
	const std::string message_prefix = "TLS::Config::T::setCAPath\n";

	if (tls_config_set_ca_path (this->tls_config.get (), ca_path.data ()))
	{
		throw Failure::Error::T (message_prefix +
		    "Failed to set TLS config CA path: " +
		    tls_config_error (this->tls_config.get ()) + "\n");
	}
}
