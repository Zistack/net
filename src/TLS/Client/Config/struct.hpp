struct T : TLS::Config::T
{
	T (const std::string & ca_path, const std::string & server_name);

	T (const std::string & ca_path,
	    const std::string & server_name,
	    const std::string & private_key_filename,
	    const std::string & certificate_filename);

	T (JSON::Value::T * config_value);

	T (T && other) = default;

	T &
	operator= (T && other) = default;

	const std::string &
	serverName () const;

	~T () = default;

	std::string server_name;
};
