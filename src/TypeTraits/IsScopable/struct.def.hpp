template
<
	typename Scopable,
	typename ... Arguments
>
struct T
:	std::is_constructible
	<
		Scope::T <std::remove_reference_t <Scopable>>,
		std::remove_reference_t <Scopable> &,
		Arguments ...
	>
{
};
