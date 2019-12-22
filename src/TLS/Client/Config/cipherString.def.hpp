const GetConfig::String::T::Value &
T::cipherString () const
{
	return this -> value <Spec::CIPHER_STRING> ();
}

GetConfig::String::T::Value &
T::cipherString ()
{
	return this -> value <Spec::CIPHER_STRING> ();
}
