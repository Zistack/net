template <typename InputStream>
void
expect (InputStream && input_stream, char e);

template
<
	typename InputStream,
	typename Predicate,
	typename = typename std::enable_if_t
	<
		std::is_invocable_r_v <bool, Predicate, char>
	>
>
char
expect (InputStream && input_stream, Predicate && classPredicate);

template <typename InputStream>
void
expect (InputStream && input_stream, std::string expected);
