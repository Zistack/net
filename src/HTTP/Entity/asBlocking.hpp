IO::Interface::ByteBlock::T &
T::asBlocking ()
{
	throw Failure::Error::T (
	    "Entity storage type does not expose blocking stream interface\n");
}
