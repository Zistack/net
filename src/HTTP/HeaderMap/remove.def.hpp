void
T::remove (const std::string & field_name)
{
	this -> m_map . erase (normalize (field_name));
}
