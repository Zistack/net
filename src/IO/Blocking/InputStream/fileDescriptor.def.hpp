template <typename NonblockingInputStream>
int
T <NonblockingInputStream>::fileDescriptor () const
{
	return this -> m_input_stream . fileDescriptor ();
}
