template <typename OutputStream>
struct T
{
	T
	(
		uint64_t count,
		OutputStream output_stream,
		OutputEntitySlot::T & entity_slot
	);

	template <typename InputStream>
	void
	operator () (InputStream && input_stream);

	~T () = default;

private:

	uint64_t count;
	OutputStream output_stream;
	OutputEntitySlot::T & entity_slot;
};

template <typename OutputStream>
T
(
	uint64_t count,
	OutputStream && output_stream,
	OutputEntitySlot::T & entity_slot
) -> T <OutputStream>;
