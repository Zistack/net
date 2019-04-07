std::chrono::milliseconds
T::getInputTimeout () const
{
	return std::chrono::milliseconds (this -> get <Spec::INPUT_TIMEOUT> ());
}
