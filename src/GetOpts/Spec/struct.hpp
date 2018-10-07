struct T
{
	T (std::initializer_list<OptionSpec::T> options);

	bool
	contains (const std::string & long_name) const;

	bool
	contains (char short_name) const;

	const OptionSpec::T &
	at (const std::string & long_name) const;

	const OptionSpec::T &
	at (char short_name) const;

	// Print help?

	~T () = default;

	std::set<OptionSpec::T> options;
	std::unordered_map<std::string, const OptionSpec::T &> long_map;
	std::unordered_map<char, const OptionSpec::T &> short_map;
};
