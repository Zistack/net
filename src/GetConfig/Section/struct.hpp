struct T : MemberType::T
{
	// For templates
	using ValueType = T;

	// For convenience
	template <typename Type>
	using IsMemberType = std::is_base_of<MemberType::T, Type>;

	T (const SectionSpec::T & spec);

	void
	readFrom (IO::Interface::PeekableInputStream::T & input_stream) override;

	// For templates
	void
	set (const ValueType & value);

	// For convenience
	template <typename Type,
	    typename = typename std::enable_if<IsMemberType<Type>::value>::type>
	void
	set (std::string identifier, std::optional<Type::ValueType> value);

	void
	validate ();

	// For templates
	const ValueType &
	get ();

	// For convenience
	template <typename Type,
	    typename = typename std::enable_if<IsMemberType<Type>::value>::type>
	std::optional<Type::ValueType>
	get (std::string identifier);

	void
	writeTo (IO::Interface::OutputStream::T & output_stream) const override;

	~T () = default;

	private:
	// Helpers for convenience methods

	void
	set (const std::string identifier,
	    std::unique_ptr<MemberType::T> && member);

	const Member::T *
	get (const std::string identifier);

	// Members

	std::unordered_map<std::string, Member::T> members;
};
