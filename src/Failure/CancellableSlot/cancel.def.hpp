template <typename ... Cancellables>
void
T <Cancellables ...>::cancel ()
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_cancelled) return;

	this -> m_cancelled = true;

	this -> callCancellable ();
}
