template
<
	typename OutputStream,
	bool is_buffered = IsBuffered::T <OutputStream>::value
>
struct T;
