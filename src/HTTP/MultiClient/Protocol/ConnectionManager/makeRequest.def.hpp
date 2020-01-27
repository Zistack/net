template <template <typename> typename ClientService>
Response::T
T <ClientService>::makeRequest (size_t connection_index, Request::T && request)
{
	return this ->
		m_connections [connection_index] .
		makeRequest (std::move (request));
}
