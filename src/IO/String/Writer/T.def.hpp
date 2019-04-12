T::T (Data::T & string) : string (string), pointer (0)
{
}

T::T (Data::T & string, Size::T initial_position)
:	string (string), pointer (initial_position)
{
}
