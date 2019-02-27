void
T::setFIFOProtocolConfig (
    const FIFOProtocol::Server::Config::Value::T & fifo_protocol_config)
{
	this->set<FIFOProtocol::Server::Config::Type::T> (
	    Spec::T::FIFO_PROTOCOL_CONFIG, fifo_protocol_config);
}
