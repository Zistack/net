template <class Element>
void
T<Element>::close ()
{
	this->queue.close ();

	this->queue.flush ();
}
