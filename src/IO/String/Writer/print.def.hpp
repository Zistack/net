void
T::print (const std::string & string)
{
	this -> m_string . replace (this -> m_pointer, string . size (), string);

	this -> m_pointer += string . size ();
}
