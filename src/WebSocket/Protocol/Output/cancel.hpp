void
T::cancel ()
{
	this->cancel (CloseMessage::T ());
}

void
T::cancel (const CloseMessage::T & close_message)
{
	{
		std::unique_lock close_lock (this->close_mutex);

		if (this->close_bit)
		{
			this->close_message = close_message;
		}
	}

	this->message_sender.cancel ();
	this->ping_pong_sender.cancel ();
}
