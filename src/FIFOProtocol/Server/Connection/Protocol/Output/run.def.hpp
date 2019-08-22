template <typename Protocol, typename Response, typename Details>
template <typename OutputStream>
void
T <Protocol, Response, Details>::run (OutputStream && output_stream)
{
	Scope::T response_scope (std::move (this -> m_response_scope));

	while (true)
	{
		Thread::Delay::T <Response> response_delay;

		try
		{
			response_delay = this -> m_response_queue . pop ();
		}
		catch (Failure::EndOfResource::T)
		{
			// This happens when the queue is closed.

			return;
		}

		Response response;

		try
		{
			response = std::move (response_delay . get ());
		}
		catch (Failure::CancelException::T)
		{
			// This happens when an error occurs while computing a response for a
			// request.  That error will be reported elsewhere.

			return;
		}

		try
		{
			this -> details () . writeResponse
			(
				response,
				std::forward <OutputStream> (output_stream)
			);
		}
		catch (Failure::EndOfResource::T)
		{
			// This happens when the protocol details want to shut down the
			// protocol.

			// I _might_ want to wrap this cast in an accessor method.
			static_cast <Protocol &> (* this) . cancel ();

			return;
		}
	}
}
