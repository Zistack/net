void
T::cancel () noexcept
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	this -> cancelled = true;

	for (auto & [id, thread] : this->threads) thread.cancel ();
}
