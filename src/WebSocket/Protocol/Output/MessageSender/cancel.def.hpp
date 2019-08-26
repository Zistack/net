template <typename Output>
void
T <Output>::cancel ()
{
	this -> m_output_queue . cancel ();
}
