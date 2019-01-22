void
T::output (Failure::CancelScope::T & output_cancel_scope)
{
	IO::CancelSignal::T output_timeout_signal;
	IO::Blocking::OutputStream::T output_stream (
	    *this->nonblocking_output_stream, output_timeout_signal);

	try
	{
		Thread::Nursery::T nursery (this->exception_store);
		Failure::CancelScope::Bind::T cancel_scope_binding (
		    output_cancel_scope, nursery);

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
	catch (Failure::ResourceError::T)
	{
		throw;
	}
	catch (const Failure::SemanticError::T & e)
	{
		exception_store.store (e);
	}

	this->sendCloseFrame (output_stream, output_timeout_signal);

	this->exception_store.poll ();
}
