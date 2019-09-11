template <typename InputStream>
struct T
{
	T
	(
		InputStream input_stream,
		uint64_t count,
		InputEntitySlot::T & entity_slot
	);

	template <typename OutputStream>
	void
	operator () (OutputStream && output_stream);

	~T () = default;

private:

	InputStream m_input_stream;
	uint64_t m_count;
	InputEntitySlot::T & m_entity_slot;
};

template <typename InputStream>
T
(
	InputStream && input_stream,
	uint64_t count,
	InputEntitySlot::T & entity_slot
) -> T <InputStream>;
