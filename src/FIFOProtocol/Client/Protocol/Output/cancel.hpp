template <typename Request, typename Interface>
void
T<Request, Interface>::cancel ()
{
	this->request_queue.cancel ();
}
