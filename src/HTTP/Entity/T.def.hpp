T::T () : data (std::in_place_type <IO::TempFile::T>, "HTTP-Entity-XXXXXX")
{
}

T::T (size_t entity_size, size_t temp_file_threshhold)
:	data (newData (entity_size, temp_file_threshhold))
{
}
