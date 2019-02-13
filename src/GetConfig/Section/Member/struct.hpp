struct T
{
	T (bool optional, std::unique_ptr<MemberType::T> && member);

	T (const T & other);

	~T () = default;

	bool optional;
	std::unique_ptr<MemberType::T> member;
};
