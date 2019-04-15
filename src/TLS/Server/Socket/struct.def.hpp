struct T : TLS::Socket::T
{
	T (const Config::T & config);

	std::unique_ptr <Connection::Socket::T>
	accept ();

	IO::Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	~T () = default;
};

static_assert (IO::TypeTraits::IsWatchable::T <T>::value);
