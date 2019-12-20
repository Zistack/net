bool
isRegisteredName (const T & host)
{
	return std::holds_alternative <RegisteredName::T> (host);
}
