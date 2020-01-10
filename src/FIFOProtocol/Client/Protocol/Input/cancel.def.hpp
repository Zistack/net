template <typename Interface, typename Response>
void
T <Interface, Response>::cancel ()
{
	this -> m_input_shutdown_signal . cancel ();
	this -> m_response_queue . cancel ();

	if constexpr (HooksLoadEvents::HasQueueIdle::T <Interface>::value)
	{
		this -> interface () . queueIdle ();
	}
}
