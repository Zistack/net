template <typename Request, typename Response, typename Interface>
void
T<Request, Response, Interface>::cancel ()
{
	this->input_shutdown_signal.cancel ();
}
