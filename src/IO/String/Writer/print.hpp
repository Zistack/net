void
T::print (const std::string & string)
{
	this->string.insert (this->pointer, string);

	this->pointer += string.size ();
}
