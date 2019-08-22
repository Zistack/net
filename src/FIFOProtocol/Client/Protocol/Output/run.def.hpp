template <typename Protocol, typename Request, typename Details>
template <typename OutputStream>
void
T <Protocol, Request, Details>::run (OutputStream && output_stream)
{
	Scope::T request_scope (std::move (this -> m_request_scope));

	try
	{
		while (true)
		{
			this -> details () . writeRequest
			(
				this -> m_request_queue . pop (),
				std::forward <OutputStream> (output_stream)
			);
		}
	}
	catch (Failure::EndOfResource::T)
	{
	}
}
