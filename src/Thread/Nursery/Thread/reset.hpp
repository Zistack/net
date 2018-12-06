void
T::reset () noexcept
{
	if (this->cancellable) this->cancellable = nullptr;
	if (this->thread.joinable ()) this->thread.detach ();
}
