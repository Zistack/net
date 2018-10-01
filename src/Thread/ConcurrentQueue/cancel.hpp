template <class Element>
void
T<Element>::cancel ()
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);

	this->closed = true;

	this->condition_variable.notify_one ();
}
