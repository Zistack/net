struct T
{
	T (std::initializer_list<Member::Spec::T> members);

	void
	printHelp (IO::Interface::OutputStream::T & output_stream,
	    size_t columns,
	    size_t tabwidth,
	    size_t indentation) const;

	~T () = default;

	std::set<Member::Spec::T> members;
};
