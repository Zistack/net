template <typename OutputStream>
template <typename InputStream>
void
T <OutputStream>::operator () (InputStream && input_stream)
{
	Failure::MaybeCancellableScope::T entity_scope
	(
		this -> m_entity_slot,
		input_stream
	);

	Util::transfer
	(
		std::forward <InputStream> (input_stream),
		this -> m_count,
		std::forward <OutputStream> (this -> m_output_stream)
	);
}
