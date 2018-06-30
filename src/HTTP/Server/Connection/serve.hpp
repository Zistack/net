void
serve (ResponsePromise::T * response_promise, Request::T * request)
{
	try
	{
		Response::T * response = handle (request);

		response_promise.put (response);
	}
	catch (const CodeError::T& e)
	{
		response_promise.put
		(
			new Response::T (e.code, this -> server -> uri, "1.1", {}, NULL)
		);
	}
}
