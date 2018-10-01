void
T::run (IO::Interface::NonblockingInputStream::T * input_stream,
    IO::Interface::NonblockingOutputStream::T * output_stream)
{
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
	// This here is a clear indicator that we should be using RAII here.
	catch (...)
	{
		this->current_protocol = this->initial_protocol;
		throw;
	}
	this->current_protocol = this->initial_protocol;
}
