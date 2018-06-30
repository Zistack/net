Response::T *
get ()
{
	std::shared_lock lock (mutex);

	while (! complete) condition_varialbe.wait (lock);

	return response;
}
