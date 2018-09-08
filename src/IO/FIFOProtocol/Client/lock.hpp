template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::lock ()
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);
	while (this->locked)
	{
		this->condition_variable.wait (lock);
	}
	this->locked = true;
}
