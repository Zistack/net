template <typename Element>
void
T <Element>::open ()
{
	std::unique_lock lock (this -> m_mutex);

	this -> m_closed = false;

	this -> m_condition_variable . notify_one ();
}
