template <typename Dispatcher>
void
T <Dispatcher>::cancel ()
{
	this -> input () . cancel ();
	this -> output () . cancel ();
}
