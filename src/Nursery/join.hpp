void
join ()
{
	std::unique_lock lock (this -> mutex);

	while (! this -> threads.empty ()) this -> condition_variable.wait (lock);
}
