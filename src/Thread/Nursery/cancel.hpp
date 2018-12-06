void
T::cancel () noexcept
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	for (auto & [id, thread] : this->threads) thread.cancel ();
}
