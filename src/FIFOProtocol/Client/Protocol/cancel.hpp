template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::cancel ()
{
	this->input.cancel ();
	this->output.cancel ();
}
