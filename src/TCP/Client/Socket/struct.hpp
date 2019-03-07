struct T : TCP::Socket::T
{
	T (const Config::T & config);

	~T () = default;
};
