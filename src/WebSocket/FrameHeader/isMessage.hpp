bool
T::isMessage () const
{
	return (this -> opcode == Type::TEXT) || (this -> opcode == Type::BINARY);
}
