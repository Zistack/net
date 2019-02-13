struct T
{
	T (std::string identifier,
	    MemberType::Spec::T member_type,
	    std::string description,
	    bool optional,
	    std::unique_ptr<MemberType> && default_value = nullptr);

	void
	printHelp (IO::Interface::OutputStream::T & output_stream);

	~T () = default;

	std::string identifier;
	MemberType::Spec::T member_type;
	std::string description;
	bool optional;
	std::unique_ptr<MemberType::T> default_value;
};
