void
T::finish ()
{
	std::thread::id this_thread_id = std::this_thread::get_id ();

	std::unique_lock<decltype (this->m)> lock (this->m);

	std::thread * this_thread = this->threads.at (this_thread_id).first;

	this->threads.erase (this_thread_id);
	this_thread->detach ();
	delete this_thread;

	if (this->threads.empty ()) this->c.notify_all ();
}
