void
T::put (char c)
{
	while (!this->output_stream.write (&c, 1))
	{
		Util::wait (this->output_stream, this->signal);
	}
}
