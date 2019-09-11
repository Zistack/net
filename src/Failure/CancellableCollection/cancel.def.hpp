template <typename Cancellable>
void
T <Cancellable>::cancel ()
{
	for (Cancellable * cancellable : this -> m_cancellables)
	{
		cancellable -> cancel ();
	}
}
