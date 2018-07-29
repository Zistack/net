void
T::put (char c)
{
	do
		Util::wait (this->output_stream, this->signal);
	while (!this->output_stream.write (&c, 1));
}
