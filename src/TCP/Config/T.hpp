T::T (const NullableString::T & hostname, const NullableString::T & port) :
    hostname (hostname),
    port (port)
{
}

T::T (JSON::Value::T * config_value)
{
	const std::string message_prefix = "TCP::Config::T::T\n";

	if (!config_value)
	{
		throw Failure::Error::T (
		    message_prefix + "Configuration must be non-null\n");
	}

	try
	{
		JSON::Object::T & config_object = config_value->asObject ();

		JSON::Value::T * hostname_value = config_object.at ("Hostname");
		if (hostname_value) this->hostname = hostname_value->asString ();

		JSON::Value::T * port_value = config_object.at ("Port");
		if (port_value) this->port = port_value->asString ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
