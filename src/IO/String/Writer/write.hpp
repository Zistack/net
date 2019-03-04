void
T::write (const char * buffer, size_t count)
{
	this->string.insert (this->pointer, buffer, count);

	this->pointer += count;
}
