template <typename PeekableInputStream>
bool
test (PeekableInputStream && input_stream, char e);

template
<
	typename PeekableInputStream,
	typename Predicate,
	typename = typename std::enable_if_t
	<
		std::is_invocable_r_v <bool, Predicate, char>
	>
>
bool
test (PeekableInputStream && input_stream, Predicate && classPredicate);
