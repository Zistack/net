template <typename ValueType, const Spec::T & spec>
struct T : GetConfig::Member::ValueImpl::T<ValueType>
{
	using InterfaceType = T;

	template <typename Type>
	using IsMemberType = std::is_base_of<GetConfig::Member::Type::T, Type>;

	T () = default;

	T (IO::Interface::PeekableInputStream::T & input_stream);

	void
	readFrom (IO::Interface::PeekableInputStream::T & input_stream);

	template <typename MemberType,
	    typename =
	        typename std::enable_if<IsMemberType<MemberType>::value>::type>
	void
	set (const std::string & identifier,
	    std::optional<typename MemberType::ValueType::InterfaceType> value);

	void
	validate () const;

	template <typename MemberType,
	    typename =
	        typename std::enable_if<IsMemberType<MemberType>::value>::type>
	std::optional<typename MemberType::ValueType::InterfaceType>
	get (const std::string & identifier) const;

	const InterfaceType &
	get () const;

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const;

	~T () = default;

	private:
	std::map<std::string, Member::T> members;
};
