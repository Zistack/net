Response::T
T::map (const Request::T & request)
{
	try
	{
		request . check ();

		return this -> responder . respond (request);
	}
	catch (const CodeError::T & e)
	{
		return e . toResponse (this -> temp_file_threshhold);
	}
}
