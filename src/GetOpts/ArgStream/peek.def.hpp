char *
T::peek () const
{
	if (this -> argi >= this -> argc) return nullptr;
	return * this -> argp;
}
