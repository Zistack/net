template <typename InputStream>
Response::T
T::readResponse (InputStream && input_stream) const
{
	Input::CancellableSlot::T <InputStream> input_slot;

	try
	{
		Response::T response;

		{
			Thread::Timer::T input_timer
			(
				this -> input_timeout,
				& decltype (input_slot)::cancel,
				& input_slot
			);

			response = std::move (
				Response::T
				(
					std::forward <InputStream> (input_stream),
					input_slot,
					this -> temp_file_threshhold
				)
			);
		}
		if constexpr (IO::TypeTraits::IsClearable::T <InputStream>::value)
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
