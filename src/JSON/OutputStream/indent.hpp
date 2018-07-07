void
T::indent ()
{
	unsigned int i;
	for (i = 0; i < this->indentation; ++i) this->output_stream->put ('\t');
}
