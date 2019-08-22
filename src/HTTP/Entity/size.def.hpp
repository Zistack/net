uint64_t
T::size () const
{
	return std::visit
	(
		[] (auto && data) { return (uint64_t) data . size (); },
		this -> m_data
	);
}
