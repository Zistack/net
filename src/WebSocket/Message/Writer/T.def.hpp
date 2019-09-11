template <typename InputStream>
T <InputStream>::T
(
	InputStream input_stream,
	uint64_t count,
	InputEntitySlot::T & entity_slot
)
:	m_input_stream (std::forward <InputStream> (input_stream)),
	m_count (count),
	m_entity_slot (entity_slot)
{
}
