T::~T ()
{
	delete this->input_stream;
	delete this->output_stream;

	close (this->read_file_descriptor);
	close (this->write_file_descriptor);
}
