T::T () : T (newPipe ()) {}

T::T (std::pair<int, int> pipe_file_descriptors) :
    T (pipe_file_descriptors.first, pipe_file_descriptors.second)
{
}

T::T (int read_file_descriptor, int write_file_descriptor) :
    read_file_descriptor (read_file_descriptor),
    write_file_descriptor (write_file_descriptor),
    is_shutdown (false),
    input_stream (read_file_descriptor),
    output_stream (write_file_descriptor)
{
}
