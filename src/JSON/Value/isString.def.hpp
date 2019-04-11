bool
T::isString () const
{
	return std::holds_alternative <String::T> (this -> contents);
}
