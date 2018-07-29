T::~T ()
{
	close (this->file_descriptor);
	unlink (this->name);
	delete this->name;
}
