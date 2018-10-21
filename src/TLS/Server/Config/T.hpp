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
		throw Failure::Error::T (
		    message_prefix + "Configuration must be non-null\n");

	JSON::Object::T * config_object = config_value->asObject ();

	JSON::Value::T * ca_path_value = config_object->at ("CA Path");

	if (ca_path_value)
	{
		JSON::String::T * ca_path_string = ca_path_value->asString ();

		this->setCAPath (ca_path_string->value ());
	}

	JSON::Value::T * private_key_filename_value =
	    config_object->at ("Private Key");
	JSON::Value::T * certificate_filename_value =
	    config_object->at ("Certificate");

	if (private_key_filename_value && certificate_filename_value)
	{
		JSON::String::T * private_key_filename_string =
		    private_key_filename_value->asString ();
		JSON::String::T * certificate_filename_string =
		    certificate_filename_value->asString ();

		this->setIdentity (private_key_filename_string->value (),
		    certificate_filename_string->value ());
	}
	else if (private_key_filename_value || certificate_filename_value)
	{
		throw Failure::Error::T (message_prefix +
		    "Private key and certificate must be specified together\n");
	}
	else
	{
		throw Failure::Error::T (
		    message_prefix + "Private key and certificate must be specified\n");
	}
}
