T::T (Duration::T timeout, std::function <void (void)> callback) :
	mutex (new std::mutex ()),
	cancelled (new bool (false))
{
	std::thread timer_thread
	(
		this -> run,
		timeout,
		this -> mutex,
		this -> cancelled,
		callback
	);
	timer_thread . detach ();
}
