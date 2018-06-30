template <typename Function, typename Args...>
run (Function function, Args args...)
{
	try
	{
		function (args);
	}
	catch (std::exception e) this -> exception_store -> store (e);

	std::unique_lock lock (this -> mutex);

	std::thread::id this_thread_id = std::this_thread::get_id ();
	std::thread * this_thread = threads.at (this_thread_id);

	this -> threads.erase (this_thread_id);

	this_thread.detach ();

	delete this_thread;

	if (this -> threads.empty ()) this -> condition_variable.notify_all ();
}
