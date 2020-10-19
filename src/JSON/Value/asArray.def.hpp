const Array::T &
T::asArray () const
{
	return std::get <Array::T> (this -> m_contents);
}

Array::T &
T::asArray ()
{
	return std::get <Array::T> (this -> m_contents);
}
