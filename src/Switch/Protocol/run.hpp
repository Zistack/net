void
T::run (IO::Interface::NonblockingInputStream::T * input_stream,
    IO::Interface::NonblockingOutputStream::T * output_stream)
{
	Failure::CleanupAction::T cleanup (
	    [this]() { this->current_protocol = this->initial_protocol; });

	try
	{
		while (true)
		{
			try
			{
				this->current_protocol->run (input_stream, output_stream);
			}
			catch (const NewProtocol::T & e)
			{
				this->current_protocol.reset (e.protocol ());
				continue;
			}
			break;
		}
	}
	catch (...)
	{
		throw;
	}
}
