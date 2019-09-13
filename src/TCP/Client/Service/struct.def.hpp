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

	Protocol m_protocol;
	Config::T m_config;
};

template <typename Protocol>
T (Protocol && protocol, const Config::T & config) -> T <Protocol>;

static_assert
(
	Failure::TypeTraits::IsCancellable::T <IO::TypeTraits::Protocol::T>::value
);
