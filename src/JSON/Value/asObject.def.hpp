const Object::T &
T::asObject () const
{
	return std::get <Object::T> (this -> m_contents);
}

Object::T &
T::asObject ()
{
	return std::get <Object::T> (this -> m_contents);
}
