template <typename Element>
void
T <Element>::close ()
{
	std::unique_lock lock (this -> m_mutex);

	this -> m_closed = true;

	this -> m_condition_variable . notify_one ();
}
