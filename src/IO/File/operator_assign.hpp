T &
T::operator= (T && other)
{
	this->file_descriptor = other.file_descriptor;
	other.file_descriptor = -1;

	return *this;
}
