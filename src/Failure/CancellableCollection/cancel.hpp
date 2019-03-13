template <typename Cancellable>
void
T<Cancellable>::cancel ()
{
	for (Cancellable * cancellable : this->cancellables)
	{
		cancellable->cancel ();
	}
}
