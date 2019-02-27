FIFOProtocol::Client::Config::Value::T
T::getFIFOProtocolConfig () const
{
	return this
	    ->get<FIFOProtocol::Client::Config::Type::T> (
	        Spec::T::FIFO_PROTOCOL_CONFIG)
	    .value ();
}
