template <typename InputStream>
template <typename OutputStream>
void
T <InputStream>::operator () (OutputStream && output_stream)
{
	if constexpr (Failure::TypeTraits::IsCancellable::T <OutputStream>::value)
	{
		Scope::T entity_scope (this -> entity_slot, output_stream);

		Util::transfer
		(
			std::forward <InputStream> (this -> input_stream),
			this -> count,
			std::forward <OutputStream> (output_stream)
		);
	}
	else
	{
		Util::transfer
		(
			std::forward <InputStream> (this -> input_stream),
			this -> count,
			std::forward <OutputStream> (output_stream)
		);
	}
}
