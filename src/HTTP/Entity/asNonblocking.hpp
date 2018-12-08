IO::Interface::NonblockingByteBlock::T &
T::asNonblocking ()
{
	throw Failure::Error::T (
	    "Entity storage type does not expose nonblocking stream interface\n");
}
