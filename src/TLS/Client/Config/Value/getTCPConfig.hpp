TCP::Config::Value::T
T::getTCPConfig () const
{
	return this->get<TCP::Config::Type::T> (Spec::T::TCP_CONFIG).value ();
}
