const char *
T::what () const noexcept
{
	return this -> m_message . data ();
}
