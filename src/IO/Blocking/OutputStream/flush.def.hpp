template <typename NonblockingOutputStream>
void
T <NonblockingOutputStream>::flush ()
{
	if (! this -> m_next) return;

	this -> send (this -> m_buffer, this -> m_next);

	this -> m_next = 0;
}
