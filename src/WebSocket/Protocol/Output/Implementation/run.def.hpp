template <typename Protocol>
template <typename OutputStream>
void
T <Protocol>::run (OutputStream && output_stream)
{
	Failure::ExceptionStore::T exception_store;

	{
		Scope::T close_scope (std::move (this -> m_close_scope));

		Thread::Nursery::T nursery (exception_store);

		nursery . add
		(
			this -> messageSender (),
			& MessageSender::
				T <Interface::T <Protocol>>::
				template run <OutputStream>,
			& this -> messageSender (),
			std::forward <OutputStream> (output_stream)
		);

		nursery . run
		(
			this -> pingPongSender (),
			& PingPongSender::
				T <Interface::T <Protocol>>::
				template run <OutputStream>,
			& this -> pingPongSender (),
			std::forward <OutputStream> (output_stream)
		);
	}

	this -> close (std::forward <OutputStream> (output_stream));
	this -> m_close_message = CloseMessage::T ();

	exception_store . poll ();
}
