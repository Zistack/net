template <typename OutputStream>
void
T::run (OutputStream && output_stream)
{
	Failure::ExceptionStore::T exception_store;

	{
		Scope::T close_scope (std::move (this -> close_scope));

		Thread::Nursery::T nursery (exception_store);

		nursery . add
		(
			this -> message_sender,
			& MessageSender::T::run <OutputStream>,
			& this -> message_sender,
			std::forward <OutputStream> (output_stream)
		);

		nursery . run
		(
			this->ping_pong_sender,
			& PingPongSender::T::run <OutputStream>,
			& this -> ping_pong_sender,
			std::forward <OutputStream> (output_stream)
		);
	}

	this -> close (std::forward <OutputStream> (output_stream));
	this -> close_message = CloseMessage::T ();

	exception_store . poll ();
}
