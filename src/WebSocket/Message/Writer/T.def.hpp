template <typename InputStream>
T <InputStream>::T
(
	InputStream input_stream,
	uint64_t count,
	InputEntitySlot::T & entity_slot
)
:	input_stream (std::forward <InputStream> (input_stream)),
	count (count),
	entity_slot (entity_slot)
{
}
