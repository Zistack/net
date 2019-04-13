T::T () : data (std::in_place_type <IO::TempFile::T>, "HTTP-Entity-XXXXXX")
{
}

T::T (uint64_t entity_size, uint64_t temp_file_threshhold)
:	data (newData (entity_size, temp_file_threshhold))
{
}
