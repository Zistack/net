template <class Element>
void
T<Element>::reset ()
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);

	this->closed = false;

	this->condition_variable.notify_one ();
}