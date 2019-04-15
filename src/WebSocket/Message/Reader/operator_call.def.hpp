template <typename OutputStream>
template <typename InputStream>
void
T <OutputStream>::operator () (InputStream && input_stream)
{
	if constexpr (Failure::TypeTraits::IsCancellable::T <InputStream>::value)
	{
		Scope::T entity_scope (this -> entity_slot, input_stream);

		Util::transfer
		(
			std::forward <InputStream> (input_stream),
			this -> count,
			std::forward <OutputStream> (this -> output_stream)
		);
	}
	else
	{
		Util::transfer
		(
			std::forward <InputStream> (input_stream),
			this -> count,
			std::forward <OutputStream> (this -> output_stream)
		);
	}
}
