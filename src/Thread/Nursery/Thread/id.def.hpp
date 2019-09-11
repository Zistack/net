std::thread::id
T::id () const noexcept
{
	if (this -> m_thread . joinable ())
	{
		return this -> m_thread . get_id ();
	}
	else
	{
		return std::this_thread::get_id ();
	}
}
