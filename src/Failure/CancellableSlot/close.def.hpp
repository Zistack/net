template <typename ... Cancellables>
void
T <Cancellables ...>::close ()
{
	std::unique_lock lock (this -> m_mutex);

	this -> m_cancellable = nullptr;
}
