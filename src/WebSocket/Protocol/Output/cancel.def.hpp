void
T::cancel ()
{
	this -> cancel (CloseMessage::T ());
}

void
T::cancel (const CloseMessage::T & close_message)
{
	{
		std::unique_lock close_lock (this -> m_close_mutex);

		if (this -> m_close_bit)
		{
			this -> m_close_message = close_message;
		}
	}

	this -> MessageSender::T <SenderInterface::T>::cancel ();
	this -> PingPongSender::T <SenderInterface::T>::cancel ();
}
