bool
T::isNull () const
{
	return std::holds_alternative <Null::T> (this -> contents);
}
