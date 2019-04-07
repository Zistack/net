T &
T::operator = (T && other)
{
	if (this -> file_descriptor != -1) close (this -> file_descriptor);

	this -> file_descriptor = other . file_descriptor;
	other . file_descriptor = -1;

	return * this;
}
