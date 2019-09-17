template <typename Cancellable>
void
T <Cancellable>::cancel ()
{
	this -> m_cancel ();
}

void
T <std::nullptr_t>::cancel ()
{
}
