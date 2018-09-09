void
T::stop ()
{
	this->close ();
	this->connections.map (
	    [](Connection::T * connection) { connection->stop (); });
}
