T &
T::operator = (T && other)
{
	this -> name = std::move (other . name);
	this -> file_descriptor = other . file_descriptor;

	other . file_descriptor = -1;

	return * this;
}
