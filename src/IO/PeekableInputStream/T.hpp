template <typename InputStream>
T<InputStream>::T (InputStream input_stream) :
    input_stream (input_stream),
    peekable (false)
{
}
