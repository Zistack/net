const char *
T::what () const noexcept
{
	return this->message.data ();
}
