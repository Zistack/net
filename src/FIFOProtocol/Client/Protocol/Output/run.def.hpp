template <typename Interface, typename Request>
template <typename OutputStream>
void
T <Interface, Request>::run (OutputStream && output_stream)
{
	Scope::T request_scope (std::move (this -> m_request_scope));

	try
	{
		while (true)
		{
			this -> interface () . writeRequest
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
