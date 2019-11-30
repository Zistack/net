template <typename Interface>
template <typename OutputStream>
void
T <Interface>::run (OutputStream && output_stream)
{
	Scope::T output_scope (std::move (this -> m_output_scope));

	try
	{
		while (true)
		{
			Message::T message (std::move (this -> m_output_queue . pop ()));

			this -> writeMessage
			(
				message,
				std::forward <OutputStream> (output_stream)
			);
		}
	}
	catch (Failure::EndOfResource::T)
	{
	}
}
