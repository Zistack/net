struct T : TCP::Socket::T
{
	T (const Config::Value::T & config);

	~T () = default;
};
