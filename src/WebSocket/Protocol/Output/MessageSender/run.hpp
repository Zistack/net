void
T::run (IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_timeout_signal)
{
	Scope::T output_scope (std::move (this->output_scope));

	try
	{
		while (true)
		{
			std::unique_ptr<Message::T> message =
			    std::move (this->output_queue.pop ());

			this->writeMessage (*message, output_stream, output_timeout_signal);
		}
	}
	catch (Failure::EndOfResource::T)
	{
	}
}
