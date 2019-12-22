template <typename Protocol>
struct T
{
	T (Protocol client_protcol, Config::T & config);

	void
	prime ();

	void
	run ();

	void
	cancel ();

	~T () = default;

private:

	Protocol m_protocol;
	Config::T m_config;
	Ciphers::T m_ciphers;
};

template <typename Protocol>
T (Protocol && protocol, Config::T & config) -> T <Protocol>;
