T::~T ()
{
	delete this->input_stream;
	delete this->output_stream;
	close (this->file_descriptor);
	unlink (this->name);
	delete this->name;
}
