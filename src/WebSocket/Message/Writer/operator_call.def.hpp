template <typename InputStream>
template <typename OutputStream>
void
T <InputStream>::operator () (OutputStream && output_stream)
{
	if constexpr (Failure::IsCancellable::T <OutputStream>::value)
	{
		Scope::T entity_scope (this -> m_entity_slot, output_stream);

		Util::transfer
		(
			std::forward <InputStream> (this -> m_input_stream),
			this -> m_count,
			std::forward <OutputStream> (output_stream)
		);

		if constexpr (IO::IsBuffered::T <OutputStream>::value)
		{
			output_stream . flush ();
		}
	}
	else
	{
		Util::transfer
		(
			std::forward <InputStream> (this -> m_input_stream),
			this -> m_count,
			std::forward <OutputStream> (output_stream)
		);

		if constexpr (IO::IsBuffered::T <OutputStream>::value)
		{
			output_stream . flush ();
		}
	}
}
