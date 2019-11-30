template <typename Interface>
void
T <Interface>::cancel ()
{
	this -> input () . cancel ();
	this -> output () . cancel ();
}
