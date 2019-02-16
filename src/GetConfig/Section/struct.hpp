struct T : MemberValue::T
{
	using InterfaceType = T;

	template <typename Type>
	using IsMemberType = std::is_base_of<MemberType::T, Type>;

	T (const SectionSpec::T & spec);

	std::unique_ptr<MemberValue::T>
	clone () const override;

	void
	readFrom (IO::Interface::PeekableInputStream::T & input_stream);

	template <typename MemberType,
	    typename =
	        typename std::enable_if<IsMemberType<MemberType>::value>::type>
	void
	set (std::string identifier,
	    std::optional<typename MemberType::ValueType::InterfaceType> value);

	void
	validate () const;

	template <typename MemberType,
	    typename =
	        typename std::enable_if<IsMemberType<MemberType>::value>::type>
	std::optional<typename MemberType::MemberValue::InterfaceType>
	get (std::string identifier) const;

	const InterfaceType &
	get () const;

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const;

	~T () = default;

	private:
	std::map<std::string, Member::T> members;
};
