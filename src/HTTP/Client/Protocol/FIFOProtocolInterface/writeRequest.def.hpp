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

			request . writeTo
			(
				std::forward <OutputStream> (output_stream),
				output_slot,
				this -> m_transfer_encoding_config
			);

			if constexpr (IO::IsBuffered::T <OutputStream>::value)
			{
				output_stream . flush ();
			}
		}
		if constexpr (IO::IsClearable::T <OutputStream>::value)
		{
			output_stream . clear ();
		}
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing request timed out\n");
	}
}
