std::string
toString (const Host::T & host)
{
	return std::visit ([] (auto && host) { return host . toString (); }, host);
}
