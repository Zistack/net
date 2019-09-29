void
T::cancel ()
{
	if (this -> m_cancelled . exchange (true)) return;
	this -> m_signal . send ();
}
