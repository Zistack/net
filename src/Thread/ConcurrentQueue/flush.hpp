void
T::flush ()
{
	std::unique_lock <decltype (this -> m)> lock (this -> m);

	this -> elements . clear ();
}
