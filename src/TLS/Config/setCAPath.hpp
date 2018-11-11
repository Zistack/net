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

bool
T::setCAPath (const JSON::Object::T & config_object)
{
	JSON::Value::T * ca_path_value = config_object.at ("CA Path");

	if (ca_path_value) this->setCAPath (ca_path_value->asString ());

	return (bool) ca_path_value;
}
