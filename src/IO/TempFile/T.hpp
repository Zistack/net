T::T (const std::string & pattern) : T (newTempFile (pattern)) {}

T::T (std::pair<std::unique_ptr<char[]>, int> temp_file) :
    T (std::move (temp_file.first), temp_file.second)
{
}

T::T (std::unique_ptr<char[]> && name, int file_descriptor) :
    name (std::move (name)),
    file_descriptor (file_descriptor),
    input_stream (file_descriptor),
    output_stream (file_descriptor)
{
}
