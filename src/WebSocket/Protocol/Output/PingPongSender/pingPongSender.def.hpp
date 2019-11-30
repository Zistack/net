template <typename Interface>
const T <Interface> &
T <Interface>::pingPongSender () const
{
	return * this;
}

template <typename Interface>
T <Interface> &
T <Interface>::pingPongSender ()
{
	return * this;
}
