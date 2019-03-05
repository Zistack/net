template <typename NonblockingOutputStream>
void
T<NonblockingOutputStream>::print (const std::string & string)
{
	this->write (string.data (), string.size ());
}
