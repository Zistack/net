const std::optional <std::string> &
T::transferEncoding () const
{
	return this -> value <Spec::TRANSFER_ENCODING> ();
}

std::optional <std::string> &
T::transferEncoding ()
{
	return this -> value <Spec::TRANSFER_ENCODING> ();
}
