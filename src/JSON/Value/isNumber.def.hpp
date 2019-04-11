bool
T::isNumber () const
{
	return std::holds_alternative <Number::T> (this -> contents);
}
