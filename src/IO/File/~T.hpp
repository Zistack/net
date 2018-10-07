T::~T ()
{
	if (this->input_stream) delete this->input_stream;
	if (this->output_stream) delete this->output_stream;

	close (this->file_descriptor);
}
