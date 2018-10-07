struct T
{
	T (const std::string & hostname, const std::string & port);
	T (JSON::Value::T * config_value);

	const char *
	hostnameCString () const;

	const char *
	portCString () const;

	~T () = default;

	std::string hostname;
	std::string port;
};
