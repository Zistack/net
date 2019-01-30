struct T : Failure::Cancellable::T
{
	T (IO::Interface::Protocol::T & protocol, const Config::T & config);

	void
	prime ();

	void
	run ();

	void
	cancel () override;

	~T () = default;

	private:
	IO::Interface::Protocol::T & protocol;
	Config::T config;
};
