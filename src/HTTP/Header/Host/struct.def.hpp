struct T
{
	T () = default;

	T (const std::string & field_value);

	T
	(
		const URI::Authority::Host::T & host,
		const std::optional <uint64_t> & port
	);

	bool
	match (const URI::T & uri);

	std::string
	toString () const;

	~T () = default;

	URI::Authority::Host::T host;
	std::optional <uint64_t> port;
};
