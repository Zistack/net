void
T::remove (const std::string & field_name)
{
	this -> m_map . erase (Util::normalize (field_name));
}
