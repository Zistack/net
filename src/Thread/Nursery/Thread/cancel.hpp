void
T::cancel () noexcept
{
	if (this->c) this->c ();
}
