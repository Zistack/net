std::unique_ptr<ConnectableContext::T>
T::newContext (IO::Interface::NonblockingInputStream::T * input_stream,
    IO::Interface::NonblockingOutputStream::T * output_stream)
{
	std::unique_ptr<ConnectableContext::T> context;

	try
	{
		IO::Signal::T signal;
		Thread::Timer::T accept_timer (
		    this->timeout, [&]() { signal.send (); });
		context = std::make_unique<Context::T> (
		    this->server_context, input_stream, output_stream, signal);
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Connection handshake timed out\n");
	}

	return context;
}
