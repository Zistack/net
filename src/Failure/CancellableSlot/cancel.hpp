template <typename Cancellable>
void
T<Cancellable>::cancel ()
{
	bool cancelled = this->cancelled.atomic_exchange (true);
	if (cancelled) return;

	Cancellable * cancellable = this->cancellable.atomic_load ();
	if (cancellable)
	{
		cancellable->cancel ();
		this->cancellable.atomic_store (nullptr);
	}
}
