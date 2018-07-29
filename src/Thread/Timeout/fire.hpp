void
T::fire (union sigval arg)
{
	((T *) arg.sival_ptr)->callback ();
}
