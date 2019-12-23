template <typename Interface, typename ... UpgradeTargets>
template <typename InputStream>
Request::T
T <Interface, UpgradeTargets ...>::readRequest
(
	InputStream && input_stream
) const
{
	Input::CancellableSlot::T <InputStream> input_slot;

	try
	{
		Request::T request;

		{
			Thread::Timer::T input_timer
			(
				this -> m_input_timeout,
				[&] () { input_slot . cancel (); }
			);

			request = Request::T
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

		return request;
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading request timed out\n");
	}
}
