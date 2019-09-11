void
T::clear ()
{
	if (this -> m_cancelled . exchange (false)) this -> m_signal . recieve ();
}
