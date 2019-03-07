template <typename Protocol>
struct T : Failure::Cancellable::T
{
	T (Protocol protocol, const Config::T & config);

	void
	prime ();

	void
	run ();

	void
	cancel () override;

	~T () = default;

	private:
	Protocol protocol;
	Config::T config;
};

template <typename Protocol>
T (Protocol && protocol, const Config::T & config)->T<Protocol>;
