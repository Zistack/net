T::T (const std::string & filename, const std::string & mode) :
    file_descriptor (newFile (filename, mode)),
    input_stream (this->file_descriptor),
    output_stream (this->file_descriptor)
{
}
