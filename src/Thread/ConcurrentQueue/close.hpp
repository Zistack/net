template <typename Element>
void
T<Element>::close ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	this->closed = true;

	this->c.notify_one ();
}
