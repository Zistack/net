template <typename Interface, typename Request, typename Response>
template <typename OutputStream>
void
T <Interface, Request, Response>::run (OutputStream && output_stream)
{
	Scope::T request_scope (std::move (this -> m_request_scope));

	try
	{
		while (true)
		{
			if constexpr
			(
				HooksLoadEvents::HasWriteActive::T <Interface>::value &&
				HooksLoadEvents::HasWriteIdle::T <Interface>::value
			)
			{
				auto request_package = this -> m_request_queue . tryPop ();

				if (! request_package)
				{
					this -> interface () . writeIdle ();
					* request_package = this -> m_request_queue . pop ();
					this -> interface () . writeActive ();
				}

				auto & [request, response_delay] = * request_package;

				this -> interface () . writeRequest
				(
					std::move (request),
					std::forward <OutputStream> (output_stream)
				);

				this -> interface () . pushInput (response_delay);
			}
			else
			{
				auto [request, response_delay] =
					this -> m_request_queue . pop ();

				this -> interface () . writeRequest
				(
					std::move (request),
					std::forward <OutputStream> (output_stream)
				);

				this -> interface () . pushInput (response_delay);
			}
		}
	}
	catch (Failure::EndOfResource::T)
	{
		this -> interface () . stopInput ();
		if constexpr (HooksLoadEvents::HasWriteIdle::T <Interface>::value)
		{
			this -> interface () . writeIdle ();
		}
	}
}
