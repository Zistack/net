template <typename ... Cancellables>
template <typename Cancellable>
void
T <Cancellables...>::open (Cancellable & cancellable)
{
	std::unique_lock lock (this -> m_mutex);

	this -> m_cancellable = cancellable;

	if (this -> m_cancelled) this -> callCancellable ();
}
