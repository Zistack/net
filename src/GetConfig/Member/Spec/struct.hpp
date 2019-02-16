struct T
{
	template <typename MemberType>
	T (std::string identifier,
	    std::string description,
	    bool optional,
	    std::optional<typename MemberType::ValueType::InterfaceType>
	        default_value = std::nullopt);

	void
	printHelp (IO::Interface::OutputStream::T & output_stream,
	    size_t columns,
	    size_t tabwidth,
	    size_t indentation) const;

	~T () = default;

	std::string identifier;
	std::string description;
	bool optional;
	std::unique_ptr<Member::T> type;
	std::unique_ptr<Value::T> default_value;
};