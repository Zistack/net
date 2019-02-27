FIFOProtocol::Server::Config::Value::T
T::getFIFOProtocolConfig () const
{
	return this
	    ->get<FIFOProtocol::Server::Config::Type::T> (
	        Spec::T::FIFO_PROTOCOL_CONFIG)
	    .value ();
}
