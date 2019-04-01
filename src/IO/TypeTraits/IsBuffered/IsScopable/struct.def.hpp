template <typename Buffered, typename>
struct T : std::false_type
{
};

template <typename Buffered>
struct T
<
	Buffered,
	Scope::T <Buffered>
> : std::true_type
{
};
