T::T () :
    pointer (0),
    peekable_input_stream (this->vector, this->pointer),
    output_stream (this->vector, this->pointer)
{
}

T::T (const std::vector<uint8_t> & vector) :
    vector (vector),
    pointer (0),
    peekable_input_stream (this->vector, this->pointer),
    output_stream (this->vector, this->pointer)
{
}

T::T (std::vector<uint8_t> && vector) :
    vector (std::move (vector)),
    pointer (0),
    peekable_input_stream (this->vector, this->pointer),
    output_stream (this->vector, this->pointer)
{
}
