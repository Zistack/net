template <class Element>
void
T<Element>::open ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	this->closed = false;

	this->c.notify_one ();
}
