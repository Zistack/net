void
init (IO::Socket::T * socket)
{
	this -> socket = socket;

	nursery.add (this -> send);
}
