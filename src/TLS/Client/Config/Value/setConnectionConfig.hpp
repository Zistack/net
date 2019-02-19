void
T::setConnectionConfig (const Connection::Config::Value::T & connection_config)
{
	this->set<Connection::Config::Type::T> (
	    Spec::T::CONNECTION_CONFIG, connection_config);
}
