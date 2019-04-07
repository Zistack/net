T &
T::operator = (T && other)
{
	this -> cancelled . store (other . cancelled . exchange (false));
	this -> signal = std::move (other . signal);

	return * this;
}
