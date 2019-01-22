void
T::prime (IO::Interface::NonblockingInputStream::T & input_stream,
    IO::Interface::NonblockingOutputStream::T & output_stream)
{
	this->nonblocking_input_stream = &input_stream;
	this->nonblocking_output_stream = &output_stream;

	{
		std::unique_lock<decltype (this->nursery_mutex)> nursery_lock (
		    this->nursery_mutex);

		this->nursery =
		    std::make_unique<Thread::Nursery::T> (this->exception_store);
	}

	this->message_sender.prime ();
	this->ping_pong_sender.prime ();
}
