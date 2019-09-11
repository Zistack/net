T &
T::operator = (T && other)
{
	this -> m_cancelled . store (other . m_cancelled . exchange (false));
	this -> m_signal = std::move (other . m_signal);

	return * this;
}
