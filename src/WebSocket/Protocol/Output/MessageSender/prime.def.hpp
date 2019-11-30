template <typename Interface>
void
T <Interface>::prime ()
{
	this -> m_output_scope = Scope::T (this -> m_output_queue);
}
