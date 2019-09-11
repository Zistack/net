template <typename Element>
void
T <Element>::flush ()
{
	std::unique_lock lock (this -> m_mutex);

	this -> m_elements . clear ();
}
