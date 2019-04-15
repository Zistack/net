template <typename Protocol>
struct T
{
	T (Protocol protocol, const Config::T & config);

	void
	prime ();

	void
	run ();

	void
	cancel ();

	~T () = default;

private:

	Protocol protocol;
	Config::T config;

	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
};

template <typename Protocol>
T (Protocol && protocol, const Config::T & config) -> T <Protocol>;
