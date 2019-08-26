template <typename Protocol>
void
T <Protocol>::cancel ()
{
	this -> cancel (CloseMessage::T ());
}

template <typename Protocol>
void
T <Protocol>::cancel (const CloseMessage::T & close_message)
{
	{
		std::unique_lock close_lock (this -> m_close_mutex);

		if (this -> m_close_bit)
		{
			this -> m_close_message = close_message;
		}
	}

	this -> messageSender () . cancel ();
	this -> pingPongSender () . cancel ();
}
