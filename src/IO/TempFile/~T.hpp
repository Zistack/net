~T (T * temp_file)
{
	delete this -> input_stream;
	delete this -> output_stream;

	close (this -> fd);
	unlink (this -> name);
	delete this -> name;
}
