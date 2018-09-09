template <class Function, class... Args>
void
T::run (Function && function, Args &&... args)
{
	try
	{
		function (args...);
	}
	catch (...)
	{
		if (this->exception_store.store (std::current_exception ()))
		{
			if (callback) callback ();
		}
	}

	std::thread::id this_thread_id = std::this_thread::get_id ();

	std::unique_lock<decltype (this->mutex)> lock (this->mutex);

	std::thread * this_thread = this->threads.at (this_thread_id);

	this->threads.erase (this_thread_id);

	this_thread->detach ();

	delete this_thread;

	if (this->threads.empty ()) this->condition_variable.notify_all ();
}
