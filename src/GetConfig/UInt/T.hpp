T::T (const InterfaceType & value) : value (value) {}

template <typename InputStream>
T::T (InputStream && input_stream) :
    value (IO::Rule::getUInt (std::forward<InputStream> (input_stream)))
{
}
