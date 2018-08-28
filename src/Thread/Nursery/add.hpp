template <class Function, class... Args>
void
T::add (Function && function, Args &&... args)
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);

	std::thread * new_thread =
	    new std::thread (&T::run<std::decay_t<Function>, std::decay_t<Args>...>,
	        this,
	        function,
	        args...);

	this->threads.insert ({new_thread->get_id (), new_thread});
}
