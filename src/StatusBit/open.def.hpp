template <class Lockable>
void
T <Lockable>::open ()
{
	std::unique_lock lock (this -> m_lockable);

	this -> m_state = true;
}
