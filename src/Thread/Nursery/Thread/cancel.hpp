void
T::cancel ()
{
	if (this->c) this->c ();
}
