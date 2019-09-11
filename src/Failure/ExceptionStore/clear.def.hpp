void
T::clear ()
{
	std::unique_lock lock (this -> m_mutex);

	this -> m_exception = nullptr;
}
