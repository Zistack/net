const Number::T &
T::asNumber () const
{
	return std::get <Number::T> (this -> m_contents);
}

Number::T &
T::asNumber ()
{
	return std::get <Number::T> (this -> m_contents);
}
