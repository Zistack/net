template <typename OutputStream>
T <OutputStream>::T
(
	uint64_t count,
	OutputStream output_stream,
	OutputEntitySlot::T & entity_slot
)
:	count (count),
	output_stream (std::forward <OutputStream> (output_stream)),
	entity_slot (entity_slot)
{
}
