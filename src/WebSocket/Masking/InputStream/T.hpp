T::T (IO::Interface::InputStream::T & input_stream,
    std::array<uint8_t, 4> masking_key) :
    input_stream (input_stream),
    masking_key (masking_key),
    i (0)
{
}
