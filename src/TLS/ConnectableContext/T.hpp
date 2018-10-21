T::T (IO::Interface::NonblockingInputStream::T * input,
    IO::Interface::NonblockingOutputStream::T * output) :
    Context::T (nullptr),
    input (input),
    output (output)
{
}
