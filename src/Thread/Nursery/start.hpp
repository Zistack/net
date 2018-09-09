void
T::start (std::function<void(void)> run, std::function<void(void)> cancel)
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	std::thread * thread = new std::thread (run);

	this->threads.insert ({thread->get_id (), {thread, cancel}});
}
