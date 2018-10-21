T::~T ()
{
	delete this->input_stream;
	delete this->output_stream;

	close (this->read_file_descriptor);
	if (!this->is_shutdown) close (this->write_file_descriptor);
}
