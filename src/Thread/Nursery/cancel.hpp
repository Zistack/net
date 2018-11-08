void
T::cancel () noexcept
{
	std::unique_lock<decltype (this->m)> lock (this->m);
	for (auto & pair : this->threads) pair.second.cancel ();
}
