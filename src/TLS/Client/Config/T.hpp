T::T (const std::string & ca_path, const std::string & server_name) :
    server_name (server_name)
{
	this->setCAPath (ca_path);
}

T::T (const std::string & ca_path,
    const std::string & server_name,
    const std::string & private_key_filename,
    const std::string & certificate_filename) :
    T (ca_path, server_name)
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

	JSON::Value::T * ca_path_value = config_object.at ("CA Path");

	if (ca_path_value)
		this->setCAPath (ca_path_value->asString ());
	else
	{
		throw Failure::Error::T (
		    message_prefix + "TLS Client must have 'CA Path' specified\n");
	}

	JSON::Value::T * server_name_value = config_object.at ("Server Name");
	if (!server_name_value) server_name_value = config_object.at ("Hostname");

	if (server_name_value)
		this->server_name = server_name_value->asString ();
	else
	{
		throw Failure::Error::T (
		    message_prefix + "TLS Client must specify a server name\n");
	}

	JSON::Value::T * private_key_filename_value =
	    config_object.at ("Private Key");
	JSON::Value::T * certificate_filename_value =
	    config_object.at ("Certificate");

	if (private_key_filename_value && certificate_filename_value)
	{
		this->setIdentity (private_key_filename_value->asString (),
		    certificate_filename_value->asString ());
	}
	else if (private_key_filename_value || certificate_filename_value)
	{
		throw Failure::Error::T (message_prefix +
		    "Private key and certificate must be specified together\n");
	}
}
