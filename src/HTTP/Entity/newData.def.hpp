Data::T
T::newData (uint64_t entity_size, uint64_t temp_file_threshhold)
{
	if (entity_size < temp_file_threshhold)
	{
		return Data::T (std::in_place_type <IO::Vector::T>);
	}
	else
	{
		return Data::T
		(
			std::in_place_type <IO::TempFile::T>,
			"HTTP-Entity-XXXXXX"
		);
	}
}
