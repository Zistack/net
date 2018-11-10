struct T : TCP::Socket::T
{
	T (const Config::T & config);

	~T () override = default;

	private:
	static int
	newSocket (const Config::T & hostname);
};
