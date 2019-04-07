std::chrono::milliseconds
T::getOutputTimeout () const
{
	return std::chrono::milliseconds (this -> get <Spec::OUTPUT_TIMEOUT> ());
}
