template <typename Interface>
template <typename InputStream>
Response::T
T <Interface>::readResponse (InputStream && input_stream) const
{
	Input::CancellableSlot::T <InputStream> input_slot;

	try
	{
		Response::T response;

		{
			Thread::Timer::T input_timer
			(
				this -> m_input_timeout,
				[&] () { input_slot . cancel (); }
			);

			response = Response::T
			(
				std::forward <InputStream> (input_stream),
				input_slot,
				this -> m_temp_file_threshhold
			);
		}
		if constexpr (IO::IsClearable::T <InputStream>::value)
		{
			input_stream . clear ();
		}

		return response;
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading response timed out\n");
	}
}
