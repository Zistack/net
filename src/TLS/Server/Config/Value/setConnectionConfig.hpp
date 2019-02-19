void
T::setConnectionConfig (
    const TLS::Connection::Config::Value::T & connection_config)
{
	this->set<TLS::Connection::Config::Type::T> (
	    Spec::T::CONNECTION_CONFIG, connection_config);
}
