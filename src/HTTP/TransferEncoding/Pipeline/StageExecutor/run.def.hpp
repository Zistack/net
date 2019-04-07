template <typename InputStream, typename Stage, typename OutputStream>
void
T <InputStream, Stage, OutputStream, true>::run ()
{
	this -> Implementation::T <InputStream, Stage, OutputStream>::run ();

	this -> pipe . shutdown ();
}
