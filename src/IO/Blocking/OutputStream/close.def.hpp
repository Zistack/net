template <typename NonblockingOutputStream>
void
T <NonblockingOutputStream>::close ()
{
	this -> flush ();
}
