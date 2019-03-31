template <typename Request, typename Interface>
template <typename OutputStream>
void
T <Request, Interface>::run (OutputStream && output_stream)
{
	Scope::T request_scope (std::move (this->request_scope));

	try
	{
		while (true)
		{
			this -> interface . writeRequest
			(
				this -> request_queue . pop (),
				std::forward <OutputStream> (output_stream)
			);
		}
	}
	catch (Failure::EndOfResource::T)
	{
	}
}
