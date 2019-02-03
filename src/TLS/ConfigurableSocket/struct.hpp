struct T : virtual Context::T
{
	T (const Config::T & config);

	virtual ~T () = default;
};
