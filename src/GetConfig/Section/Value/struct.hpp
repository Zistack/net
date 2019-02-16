struct T : GetConfig::Member::Value::T
{
	using InterfaceType = T;

	template <typename Type>
	using IsMemberType = std::is_base_of<GetConfig::Member::T, Type>;

	T (const Spec::T & spec,
	    IO::Interface::PeekableInputStream::T & input_stream);

	std::unique_ptr<GetConfig::Member::Value::T>
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
