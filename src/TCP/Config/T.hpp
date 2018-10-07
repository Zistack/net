T::T (const std::string & hostname, const std::string & port) :
    hostname (hostname),
    port (port)
{
}

T::T (JSON::Value::T * config_value) : hostname (""), port ("")
{
	const std::string message_prefix = "TCP::Config::T::T\n";

	if (!config_value)
	{
		throw Failure::Error::T (
		    message_prefix + "Expected non-null config object\n");
	}

	try
	{
		JSON::Object::T * config_object = config_value->asObject ();

		JSON::Value::T * hostname_value = config_object->at ("Hostname");
		if (hostname_value)
		{
			JSON::String::T * hostname_string = hostname_value->asString ();

			this->hostname = hostname_string->value;
		}

		JSON::Value::T * port_value = config_object->at ("Port");
		if (port_value)
		{
			JSON::String::T * port_string = port_value->asString ();

			this->port = port_string->value;
		}
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
