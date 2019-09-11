template <typename Cancellable>
void
T <Cancellable>::add (Cancellable & cancellable)
{
	this -> m_cancellables [this -> m_next] = & cancellable;
	++ this -> m_next;
}
