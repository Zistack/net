template <typename NonblockingOutputStream>
int
T <NonblockingOutputStream>::fileDescriptor () const
{
	return this -> m_output_stream . fileDescriptor ();
}
