template <typename Interface>
IO::Watchable::Events::T
T <Interface>::events () const
{
	return POLLOUT;
}
