template <typename Protocol>
struct T : Protocol
{
	template
	<
		typename ... ProtocolArguments,
		typename = std::enable_if_t
		<
			std::is_constructible_v <Protocol, ProtocolArguments ...>
		>
	>
	T (const Config::T & config, ProtocolArguments && ... protocol_arguments);

	using Protocol::prime;

	void
	run ();

	using Protocol::stop;
	using Protocol::cancel;

	~T () = default;

private:

	using Protocol::run;

	Config::T m_config;
};

static_assert (Failure::IsCancellable::T <T <IO::DummyProtocol::T>>::value);
