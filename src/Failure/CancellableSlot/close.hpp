template <typename Cancellable>
void
T<Cancellable>::close ()
{
	while (this->cancellable.atomic_load ())
	{
		std::this_thread::yield ();
	}
}
