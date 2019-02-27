void
T::setFIFOProtocolConfig (
    const FIFOProtocol::Client::Config::Value::T & fifo_protocol_config)
{
	this->set<FIFOProtocol::Client::Config::Type::T> (
	    Spec::T::FIFO_PROTOCOL_CONFIG, fifo_protocol_config);
}
