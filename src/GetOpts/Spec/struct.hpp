struct T
{
	// Maybe replace this with the usual template iterable construction later.
	T (std::string usage_suffix,
	    std::string description,
	    std::initializer_list<OptionSpec::T> options);

	bool
	contains (const std::string & long_name) const;

	bool
	contains (char short_name) const;

	const OptionSpec::T &
	at (const std::string & long_name) const;

	const OptionSpec::T &
	at (char short_name) const;

	void
	printHelp (IO::Interface::OutputStream::T & output_stream,
	    char * argv0,
	    size_t columns,
	    size_t tabwidth,
	    size_t indentation) const;

	~T () = default;

	std::set<OptionSpec::T> options;
	std::unordered_map<std::string, const OptionSpec::T &> long_map;
	std::unordered_map<char, const OptionSpec::T &> short_map;

	std::string usage_suffix;
	std::string description;
};
