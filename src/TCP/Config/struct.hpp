struct T
{
	T (const char * hostname, const char * port);
	T (JSON::Value::T * config_value);

	~T ();

	char * hostname;
	char * port;
};
