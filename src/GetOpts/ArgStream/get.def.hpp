char *
T::get ()
{
	if (this -> argi >= this -> argc) return nullptr;
	char * arg = * this -> argp;
	++ this -> argi;
	++ this -> argp;
	return arg;
}
