bool
T::isControl () const
{
	return (this -> opcode == Type::PING) || (this -> opcode == Type::PONG) || (this -> opcode == Type::CLOSE);
}
