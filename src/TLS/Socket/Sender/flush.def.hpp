template <typename Interface>
void
T <Interface>::flush ()
{
	if (! this -> m_next) return;

	this -> send (this -> m_buffer . get (), this -> m_next);

	this -> m_next = 0;
}
