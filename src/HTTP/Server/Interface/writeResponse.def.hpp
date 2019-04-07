template <typename OutputStream>
void
T::writeResponse
(
	const Response::T & response,
	OutputStream && output_stream
) const
{
	Output::CancellableSlot::T <OutputStream> output_slot;

	try
	{
		{
			Thread::Timer::T output_timer
			(
				this -> output_timeout,
				& decltype (output_slot)::cancel,
				& output_slot
			);

			if constexpr (IO::TypeTraits::IsBuffered::T <OutputStream>::value)
			{
				Scope::T output_scope (output_stream);

				response . writeTo
				(
					std::forward <OutputStream> (output_stream),
					output_slot,
					this -> transfer_encoding_config
				);
			}
			else
			{
				response . writeTo
				(
					std::forward <OutputStream> (output_stream),
					output_slot,
					this -> transfer_encoding_config
				);
			}
		}
		if constexpr (IO::TypeTraits::IsClearable::T <OutputStream>::value)
		{
			output_stream . clear ();
		}
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing response timed out\n");
	}
}
