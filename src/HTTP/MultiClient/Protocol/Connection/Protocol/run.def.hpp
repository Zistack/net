template <typename InputStream, typename OutputStream>
void
T::run (InputStream && input_stream, OutputStream && output_stream)
{
	std::unique_lock active_lock (this -> m_active_mutex);
	while (this -> running)
	{
		if (! this -> active)
		{
			this -> m_active_condition_variable . wait (active_lock);
		}
		else
		{
			this -> SimpleClientInterface::T::prime ();
			this -> primed = true;

			active_lock . unlock ();
			this -> SimpleClientInterface::T::run
			(
				std::forward <InputStream> (input_stream),
				std::forward <OutputStream> (output_stream)
			);
			active_lock . lock ();

			this -> primed = false;
		}
	}
}
