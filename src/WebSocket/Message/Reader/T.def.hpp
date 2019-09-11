template <typename OutputStream>
T <OutputStream>::T
(
	uint64_t count,
	OutputStream output_stream,
	OutputEntitySlot::T & entity_slot
)
:	m_count (count),
	m_output_stream (std::forward <OutputStream> (output_stream)),
	m_entity_slot (entity_slot)
{
}
