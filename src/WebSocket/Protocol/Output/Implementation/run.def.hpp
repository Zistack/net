template <typename Protocol>
template <typename OutputStream>
void
T <Protocol>::run (OutputStream && output_stream)
{
	Failure::ExceptionStore::T exception_store;

	{
		Scope::T close_scope (std::move (this -> m_close_scope));

		Thread::Nursery::Aggregate::T nursery
		(
			exception_store,
			std::forward_as_tuple
			(
				this -> messageSender (),
				[&] ()
				{
					this -> messageSender () . run
					(
						std::forward <OutputStream> (output_stream)
					);
				}
			),
			std::forward_as_tuple
			(
				this -> pingPongSender (),
				[&] ()
				{
					this -> pingPongSender () . run
					(
						std::forward <OutputStream> (output_stream)
					);
				}
			)
		);
	}

	this -> close (std::forward <OutputStream> (output_stream));
	this -> m_close_message = CloseMessage::T ();

	exception_store . poll ();
}
