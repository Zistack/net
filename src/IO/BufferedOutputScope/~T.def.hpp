template <typename BufferedOutputStream>
T <BufferedOutputStream>::~T ()
{
	this -> m_exception_store . tryStore
	(
		[&] () { this -> m_output_stream . flush (); }
	);
}
