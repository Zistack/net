template <typename NonblockingInputStream>
int
T <NonblockingInputStream>::fileDescriptor () const
{
	return this -> input_stream . fileDescriptor ();
}
