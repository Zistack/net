template <typename... Cancellables>
void
T<Cancellables...>::cancel ()
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);

	if (cancelled) return;

	this->cancelled = true;

	this->callCancellable ();
}
