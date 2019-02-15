struct T : MemberValue::T
{
	using InterfaceType = std::string;

	T (const std::string & value);

	std::unique_ptr<MemberValue::T>
	clone () const override;

	~T () = default;

	private:
	std::string value;
	friend class String::T;
};
