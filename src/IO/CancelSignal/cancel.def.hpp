void
T::cancel ()
{
	if (this -> m_cancelled . load ()) return;
	this -> m_signal . send ();
}
