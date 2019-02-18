void
T::setIdentity (const KeyPair::Value::T & identity)
{
	this->set<KeyPair::Type::T> (Spec::T::IDENTITY, identity);
}
