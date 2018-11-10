T::T (int file_descriptor) :
    file_descriptor (file_descriptor),
    input_stream (file_descriptor),
    output_stream (file_descriptor)
{
}
