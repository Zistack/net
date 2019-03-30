void
T::finish () noexcept
{
	std::thread::id this_thread_id = std::this_thread::get_id ();

	std::unique_lock lock (this -> m);

	Thread::T this_thread = std::move (this -> threads . at (this_thread_id));
	this -> threads . erase (this_thread_id);

	if (this -> threads . empty ()) this -> c . notify_all ();
}
