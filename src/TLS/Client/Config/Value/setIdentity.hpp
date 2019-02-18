void
T::setIdentity (std::optional<KeyPair::Value::T> identity)
{
	this->set<KeyPair::Type::T> (Spec::T::IDENTITY, identity);
}
