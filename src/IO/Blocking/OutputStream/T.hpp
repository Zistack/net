template <typename NonblockingOutputStream>
T<NonblockingOutputStream>::T (NonblockingOutputStream output_stream) :
    output_stream (output_stream),
    next (0)
{
}
