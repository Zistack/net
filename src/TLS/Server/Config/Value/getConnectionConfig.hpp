TLS::Connection::Config::Value::T
T::getConnectionConfig () const
{
	return this
	    ->get<TLS::Connection::Config::Type::T> (Spec::T::CONNECTION_CONFIG)
	    .value ();
}
