void
T::cancel ()
{
	this->output_queue.close ();
	this->output_queue.flush ();
}
