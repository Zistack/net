T::T (const std::string & private_key_filename,
    const std::string & certificate_filename,
    const std::string & ca_path)
{
	this->setIdentity (private_key_filename, certificate_filename);
	this->setCAPath (ca_path);
}

T::T (const std::string & private_key_filename,
    const std::string & certificate_filename)
{
	this->setIdentity (private_key_filename, certificate_filename);
}

T::T (JSON::Value::T * config_value)
{
	const std::string message_prefix = "TLS::Config::T::T\n";

	if (!config_value)
	{
		throw Failure::Error::T (
		    message_prefix + "Configuration must be non-null\n");
	}

	JSON::Object::T & config_object = config_value->asObject ();

	this->setCAPath (config_object);

	if (!this->setIdentity (config_object))
	{
		throw Failure::Error::T (
		    message_prefix + "Private key and certificate must be specified\n");
	}
}
