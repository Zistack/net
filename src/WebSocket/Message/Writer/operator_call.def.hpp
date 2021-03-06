template <typename InputStream>
template <typename OutputStream>
void
T <InputStream>::operator () (OutputStream && output_stream)
{
	Failure::MaybeCancellableScope::T entity_scope
	(
		this -> m_entity_slot,
		output_stream
	);

	Util::transfer
	(
		std::forward <InputStream> (this -> m_input_stream),
		this -> m_count,
		std::forward <OutputStream> (output_stream)
	);
}
