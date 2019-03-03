void
T::send (std::unique_ptr<Message::T> && message)
{
	try
	{
		this->output_queue.push (std::move (message));
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
