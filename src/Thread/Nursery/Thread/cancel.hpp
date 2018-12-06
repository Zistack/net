void
T::cancel () noexcept
{
	if (this->cancellable) this->cancellable->cancel ();
}
