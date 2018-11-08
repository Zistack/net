void
T::reset ()
{
	if (this->c) this->c = nullptr;
	if (this->thread.joinable ()) this->thread.detach ();
}
