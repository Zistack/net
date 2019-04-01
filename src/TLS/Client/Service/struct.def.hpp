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
	Protocol protocol;
	Config::T & config;
};

template <typename Protocol>
T (Protocol && protocol, Config::T & config) -> T <Protocol>;
