void
T::run (IO::Interface::NonblockingOutputStream::T & nonblocking_output_stream)
{
	Failure::ExceptionStore::T exception_store;

	IO::CancelSignal::T output_timeout_signal;
	IO::Blocking::OutputStream::T output_stream (
	    nonblocking_output_stream, output_timeout_signal);

	{
		Scope::T close_scope (std::move (this->close_scope));

		Thread::Nursery::T nursery (exception_store);

		nursery.add (this->message_sender,
		    &MessageSender::T::run,
		    &this->message_sender,
		    output_stream,
		    output_timeout_signal);

		nursery.run (this->ping_pong_sender,
		    &PingPongSender::T::run,
		    &this->ping_pong_sender,
		    output_stream,
		    output_timeout_signal);
	}

	this->close (output_stream, output_timeout_signal);
	this->close_message = CloseMessage::T ();

	exception_store.poll ();
}
