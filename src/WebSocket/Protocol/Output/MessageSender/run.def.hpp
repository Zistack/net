template <typename OutputStream>
void
T::run (OutputStream && output_stream)
{
	Scope::T output_scope (std::move (this -> output_scope));

	try
	{
		while (true)
		{
			Message::T message (std::move (this -> output_queue . pop ()));

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
