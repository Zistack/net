template <typename OutputStream>
struct T
:	std::is_constructible
	<
		BufferedOutputScope::T <std::remove_reference_t <OutputStream>>,
		std::remove_reference_t <OutputStream> &,
		Failure::ExceptionStore::T &
	>
{
};
