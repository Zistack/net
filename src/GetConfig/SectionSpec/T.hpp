template <typename Iterable, typename>
T::T (Iterable && members) : members (members.begin (), members.end ())
{
}
