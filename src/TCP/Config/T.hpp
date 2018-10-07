T::T (const char * hostname, const char * port) :
    hostname (nullptr),
    port (nullptr)
{
	if (hostname)
	{
		size_t hostname_length = strlen (hostname) + 1;
		this->hostname = new char[hostname_length];
		strncpy (this->hostname, hostname, hostname_length);
	}

	if (port)
	{
		size_t hostname_length = strlen (hostname) + 1;
		this->hostname = new char[hostname_length];
		strncpy (this->hostname, hostname, hostname_length);
	}
}

T::T (JSON::Value::T * config_value) : hostname (nullptr), port (nullptr)
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

			size_t hostname_length = hostname_string->value.size () + 1;
			this->hostname = new char[hostname_length];
			strncpy (this->hostname,
			    hostname_string->value.data (),
			    hostname_length);
		}

		JSON::Value::T * port_value = config_object->at ("Port");
		if (port_value)
		{
			JSON::String::T * port_string = port_value->asString ();

			size_t port_length = port_string->value.size () + 1;
			this->port = new char[port_length];
			strncpy (this->port, port_string->value.data (), port_length);
		}
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
