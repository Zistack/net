void
indent ()
{
	unsigned int i;
	for (i = 0; i < indentation; ++ i) output_stream -> put ('\t');
}
