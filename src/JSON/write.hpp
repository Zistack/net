void
write (Value::T * value, IO::Interface::OutputStream::T * output_stream)
{
	value->writeTo (output_stream);
}
