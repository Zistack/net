template <typename NonblockingInputStream>
T<NonblockingInputStream>::T (NonblockingInputStream input_stream) :
    input_stream (input_stream),
    begin (0),
    end (0)
{
}
