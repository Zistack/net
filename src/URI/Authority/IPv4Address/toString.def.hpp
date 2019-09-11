std::string
T::toString () const
{
	return
		std::to_string (this -> m_octets [0]) + "." +
		std::to_string (this -> m_octets [1]) + "." +
		std::to_string (this -> m_octets [2]) + "." +
		std::to_string (this -> m_octets [3]);
}
