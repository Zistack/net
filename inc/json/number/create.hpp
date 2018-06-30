T *
create (std::string base)
{
	T * number = (T *) malloc (sizeof (T));
	init (number, base);
	return number;
}
