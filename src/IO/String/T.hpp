T::T () :
    pointer (0),
    peekable_input_stream (this->string, this->pointer),
    output_stream (this->string, this->pointer)
{
}

T::T (const std::string & string) :
    string (string),
    pointer (0),
    peekable_input_stream (this->string, this->pointer),
    output_stream (this->string, this->pointer)
{
}

T::T (std::string && string) :
    string (std::move (string)),
    pointer (0),
    peekable_input_stream (this->string, this->pointer),
    output_stream (this->string, this->pointer)
{
}
