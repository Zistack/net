std::optional<KeyPair::Value::T>
T::getIdentity () const
{
	return this->get<KeyPair::Type::T> (Spec::T::IDENTITY);
}
