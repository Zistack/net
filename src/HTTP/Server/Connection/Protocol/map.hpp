Response::T
T::map (const Request::T & request)
{
	try
	{
		request.check ();

		return this->responder.respond (request);
	}
	catch (CodeError::T & e)
	{
		HeaderMap::T headers;

		std::unique_ptr<Entity::T> error_details (new BlockingEntity::T (
		    std::make_unique<IO::String::T> (e.what ())));

		return Response::T ("HTTP/1.1",
		    e.errorCode (),
		    Util::reasonPhrase (e.errorCode ()),
		    headers,
		    std::move (error_details));
	}
}
