char
T::get ()
{
	char opt = * this -> opt_ptr;

	if (opt != '\0') ++ this -> opt_ptr;

	return opt;
}
