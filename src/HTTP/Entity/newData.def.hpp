Data::T
T::newData (size_t entity_size, size_t temp_file_threshhold)
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
