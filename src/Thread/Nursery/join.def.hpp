void
T::join ()
{
	std::unique_lock lock (this -> m);

	while (! this -> threads . empty ()) this -> c . wait (lock);

	if (this -> internal_store) this -> internal_store -> poll ();
}
