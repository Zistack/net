std::chrono::milliseconds
T::getCloseTimeout () const
{
	return std::chrono::milliseconds (this -> get <Spec::CLOSE_TIMEOUT> ());
}
