void
T::check () const
{
	if (this -> e_ptr) std::rethrow_exception (this -> e_ptr);
}
