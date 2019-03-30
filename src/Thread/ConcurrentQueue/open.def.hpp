template <typename Element>
void
T <Element>::open ()
{
	std::unique_lock lock (this -> m);

	this -> closed = false;

	this -> c . notify_one ();
}
