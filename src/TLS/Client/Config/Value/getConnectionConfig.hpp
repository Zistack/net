Connection::Config::Value::T
T::getConnectionConfig () const
{
	return this->get<Connection::Config::Type::T> (Spec::T::CONNECTION_CONFIG)
	    .value ();
}
