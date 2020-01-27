HTTP::Response::T
T::makeRequest (HTTP::Request::T && request)
{
	std::unique_lock active_lock (this -> m_active_mutex);

	while (this -> active)
	{
		if (! this -> primed)
		{
			this -> m_active_condition_variable . wait (active_lock);
		}
		else
		{
			return this -> SimpleClientInterface::T::makeRequest (std::move (request));
		}
	}

	throw Failure::ServiceError::T ("Protocol is not active\n");
}
