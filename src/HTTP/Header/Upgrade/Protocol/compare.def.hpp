int
T::compare (const T & other) const
{
	int result = this -> name . compare (other . name);
	if (result) return result;

	if (! this -> version && ! other . version) return 0;
	if (! this -> version) return -1;
	if (! other . version) return 1;

	return this -> version -> compare (* other . version);
}
