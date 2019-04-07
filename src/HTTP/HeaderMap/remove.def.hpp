void
T::remove (const std::string & field_name)
{
	this -> map . erase (normalize (field_name));
}
