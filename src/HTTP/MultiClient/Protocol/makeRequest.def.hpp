template <template <typename> typename ClientService>
Response::T
T <ClientService>::makeRequest (Request::T && request)
{
	while (this -> capacityScaler () . activeConnections ())
	{
		try
		{
			return this -> connectionManager () .
				makeRequest (this -> getNextConnection (), std::move (request));
		}
		catch (Failure::EndOfResource::T)
		{
			continue;
		}
	}

	throw Failure::ServiceError::T ("Protocol is not running\n");
}
