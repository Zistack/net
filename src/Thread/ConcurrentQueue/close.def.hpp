template <typename Element>
void
T <Element>::close ()
{
	std::unique_lock lock (this -> m);

	this -> closed = true;

	this -> c . notify_one ();
}
