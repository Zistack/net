double
T::updateLoad ()
{
	double write_load = this -> m_write_load_moniter . updateLoad ();
	double queue_load = this -> m_queue_load_moniter . updateLoad ();
	double read_load = this -> m_read_load_moniter . updateLoad ();

	double load = std::max ({write_load, queue_load, read_load});

	return load;
}
