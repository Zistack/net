int
T::compare (const T & other) const
{
	if (this -> string && other . string)
	{
		return this -> string -> compare (* other . string);
	}
	if (this -> string) return 1;
	if (other . string) return -1;
	return 0;
}
