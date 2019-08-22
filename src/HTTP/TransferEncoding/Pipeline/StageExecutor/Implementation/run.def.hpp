template <typename InputStream, typename Stage, typename OutputStream>
void
T <InputStream, Stage, OutputStream>::run ()
{
	this -> m_stage . recode (this -> m_input_stream, this -> m_output_stream);
}
