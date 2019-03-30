void
T::cancel () noexcept
{
	std::unique_lock lock (this -> m);

	this -> cancelled = true;

	for (auto && [id, thread] : this -> threads) thread . cancel ();
}
