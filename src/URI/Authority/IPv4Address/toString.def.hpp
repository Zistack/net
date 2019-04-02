std::string
T::toString () const
{
	return
		std::to_string (this -> octets [0]) + "." +
		std::to_string (this -> octets [1]) + "." +
		std::to_string (this -> octets [2]) + "." +
		std::to_string (this -> octets [3]);
}
