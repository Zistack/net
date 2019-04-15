template <typename Dispatcher>
void
T <Dispatcher>::cancel ()
{
	this -> input_shutdown_signal . cancel ();
}
