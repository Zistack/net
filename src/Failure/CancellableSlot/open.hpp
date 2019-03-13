template <typename Cancellable>
void
T<Cancellable>::open (Cancellable & cancellable)
{
	this->cancellable.atomic_store (&cancellable);
	bool cancelled = this->cancelled.atomic_load ();

	if (cancelled)
	{
		cancellable.cancel ();
		cancellable.atomic_store (nullptr);
	}
}
