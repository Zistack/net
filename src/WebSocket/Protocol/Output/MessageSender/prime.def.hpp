template <typename Output>
void
T <Output>::prime ()
{
	this -> m_output_scope = Scope::T (this -> m_output_queue);
}
