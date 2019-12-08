template <typename OutputStream>
void
T::writeRequest
(
	const Request::T & request,
	OutputStream && output_stream
) const
{
	Output::CancellableSlot::T <OutputStream> output_slot;

	try
	{
		{
			Thread::Timer::T output_timer
			(
				this -> m_output_timeout,
				[&] () { output_slot . cancel (); }
			);

			if constexpr (IO::TypeTraits::IsBuffered::T <OutputStream>::value)
			{
				Scope::T output_scope (output_stream);

				request . writeTo
				(
					std::forward <OutputStream> (output_stream),
					output_slot,
					this -> m_transfer_encoding_config
				);
			}
			else
			{
				request . writeTo
				(
					std::forward <OutputStream> (output_stream),
					output_slot,
					this -> m_transfer_encoding_config
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
		throw Failure::ResourceError::T ("Writing request timed out\n");
	}
}
