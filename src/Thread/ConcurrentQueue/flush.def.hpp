template <typename Element>
void
T <Element>::flush ()
{
	std::unique_lock lock (this -> m);

	this -> elements . clear ();
}
