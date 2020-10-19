const String::T &
T::asString () const
{
	return std::get <String::T> (this -> m_contents);
}

String::T &
T::asString ()
{
	return std::get <String::T> (this -> m_contents);
}
