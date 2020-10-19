const Boolean::T &
T::asBoolean () const
{
	return std::get <Boolean::T> (this -> m_contents);
}

Boolean::T &
T::asBoolean ()
{
	return std::get <Boolean::T> (this -> m_contents);
}
