void
T::setTCPConfig (const TCP::Config::Value::T & tcp_config)
{
	this->set<TCP::Config::Type::T> (Spec::T::TCP_CONFIG, tcp_config);
}
