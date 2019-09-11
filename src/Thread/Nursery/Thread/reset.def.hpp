void
T::reset () noexcept
{
	if (this -> m_cancellable)
	{
		this -> m_cancellable = nullptr;
		this -> m_cancel_cancellable = nullptr;
	}
	if (this -> m_thread . joinable ()) this -> m_thread . detach ();
}
