void
T::write (const char * buffer, size_t count)
{
	this -> string . replace (this -> pointer, count, buffer);

	this -> pointer += count;
}
