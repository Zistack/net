template <typename Interface>
void
T <Interface>::cancelOutput ()
{
	this -> output () . cancel ();
}
