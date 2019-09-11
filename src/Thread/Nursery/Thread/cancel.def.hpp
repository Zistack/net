void
T::cancel () noexcept
{
	if (this -> m_cancellable)
	{
		this -> m_cancel_cancellable (this -> m_cancellable);
	}
}
