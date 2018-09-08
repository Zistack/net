template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::unlock ()
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);
	this->locked = false;
	this->condition_variable.notify_one ();
}
