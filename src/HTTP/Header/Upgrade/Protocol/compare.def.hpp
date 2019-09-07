int
T::compare (const T & other) const
{
	int result = this -> name . compare (other . name);
	if (result) return result;
	else return this -> version . compare (other . version);
}
