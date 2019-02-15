struct T // : MemberType::T
{
	// For templates
	using InterfaceType = T;

	// For convenience
	template <typename Type>
	using IsMemberType = std::is_base_of<MemberType::T, Type>;

	T (const SectionSpec::T & spec);

	void
	readFrom (IO::Interface::PeekableInputStream::T & input_stream);

	// For templates
	void
	set (const InterfaceType & value);

	// For convenience
	template <typename MemberType,
	    typename =
	        typename std::enable_if<IsMemberType<MemberType>::value>::type>
	void
	set (std::string identifier,
	    std::optional<typename MemberType::ValueType::InterfaceType> value);

	void
	validate () const;

	// For templates
	const InterfaceType &
	get () const;

	// For convenience
	template <typename MemberType,
	    typename =
	        typename std::enable_if<IsMemberType<MemberType>::value>::type>
	std::optional<typename MemberType::MemberValue::InterfaceType>
	get (std::string identifier) const;

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const;

	~T () = default;

	private:
	std::map<std::string, Member::T> members;
};
