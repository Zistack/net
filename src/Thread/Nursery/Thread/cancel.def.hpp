template <typename Cancellable>
void
T <Cancellable>::cancel ()
{
	this -> m_cancellable . cancel ();
}

void
T <std::nullptr_t>::cancel ()
{
}
