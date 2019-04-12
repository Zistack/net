T::T (const Data::T & string) : string (string), pointer (0)
{
}

T::T (const Data::T & string, Size::T initial_position)
:	string (string), pointer (initial_position)
{
}
