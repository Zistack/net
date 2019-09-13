template <typename Lockable>
void
T <Lockable>::close ()
{
	std::unique_lock lock (this -> m_lockable);

	this -> m_state = false;
}
