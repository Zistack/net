struct T : TLS::Config::T
{
	T (const std::string & private_key_filename,
	    const std::string & certificate_filename);

	T (const std::string & private_key_filename,
	    const std::string & certificate_filename,
	    const std::string & ca_path);

	T (JSON::Value::T * json_value);

	T (T && other) = default;

	T &
	operator= (T && other) = default;

	~T () = default;
};
