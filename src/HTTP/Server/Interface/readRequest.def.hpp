template <typename InputStream>
Request::T
T::readRequest (InputStream && input_stream) const
{
	Input::CancellableSlot::T <InputStream> input_slot;

	try
	{
		Request::T request;

		{
			Thread::Timer::T input_timer
			(
				this -> input_timeout,
				& decltype (input_slot)::cancel,
				& input_slot
			);

			request = Request::T
			(
				std::forward <InputStream> (input_stream),
				input_slot,
				this -> temp_file_threshhold
			);
		}
		if constexpr (IO::TypeTraits::IsClearable::T <InputStream>::value)
		{
			input_stream . clear ();
		}

		return request;
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading request timed out\n");
	}
}
