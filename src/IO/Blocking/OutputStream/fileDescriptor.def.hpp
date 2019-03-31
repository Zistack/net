template <typename NonblockingOutputStream>
int
T <NonblockingOutputStream>::fileDescriptor () const
{
	return this -> output_stream . fileDescriptor ();
}
