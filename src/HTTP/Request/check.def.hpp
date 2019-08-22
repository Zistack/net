void
T::check () const
{
	if (this -> m_e_ptr) std::rethrow_exception (this -> m_e_ptr);
}
