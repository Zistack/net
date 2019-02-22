template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::cancel ()
{
	this->input_shutdown_signal.cancel ();
}
