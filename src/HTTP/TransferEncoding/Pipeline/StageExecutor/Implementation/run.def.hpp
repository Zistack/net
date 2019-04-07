template <typename InputStream, typename Stage, typename OutputStream>
void
T <InputStream, Stage, OutputStream>::run ()
{
	this -> stage . recode (this -> input_stream, this -> output_stream);
}
