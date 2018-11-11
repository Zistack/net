void
T::setIdentity (const std::string & private_key_filename,
    const std::string & certificate_filename)
{
	const std::string message_prefix = "TLS::Config::T::setIdentity\n";

	if (tls_config_set_key_file (
	        this->tls_config.get (), private_key_filename.data ()))
	{
		throw Failure::Error::T (message_prefix +
		    "Failed to load private key file: " +
		    tls_config_error (this->tls_config.get ()) + "\n");
	}

	if (tls_config_set_cert_file (
	        this->tls_config.get (), certificate_filename.data ()))
	{
		throw Failure::Error::T (message_prefix +
		    "Failed to load certificate file: " +
		    tls_config_error (this->tls_config.get ()) + "\n");
	}
}

bool
T::setIdentity (const JSON::Object::T & config_object)
{
	const std::string message_prefix = "TLS::Config::T::setIdentity\n";

	JSON::Value::T * private_key_filename_value =
	    config_object.at ("Private Key");
	JSON::Value::T * certificate_filename_value =
	    config_object.at ("Certificate");

	if (private_key_filename_value && certificate_filename_value)
	{
		this->setIdentity (private_key_filename_value->asString (),
		    certificate_filename_value->asString ());
		return true;
	}
	else if (private_key_filename_value || certificate_filename_value)
	{
		throw Failure::Error::T (message_prefix +
		    "Private key and certificate must be specified together\n");
	}
	else
		return false;
}
