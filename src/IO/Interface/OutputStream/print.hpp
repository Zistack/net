void
T::print (std::basic_string <CharType> message)
{
	for (CharType c : message) this -> put (c);
}
