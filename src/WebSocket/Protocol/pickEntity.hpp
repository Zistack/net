std::unique_ptr<HTTP::Entity::T>
T::pickEntity (bool final_frame, uint64_t payload_length)
{
	if (!final_frame)
	{
		return std::make_unique<HTTP::Entity::T> (
		    std::make_unique<IO::TempFile::T> ());
	}
	else
	{
		if (payload_length > this->tmp_file_threshhold)
		{
			return std::make_unique<HTTP::Entity::T> (
			    std::make_unique<IO::TempFile::T> ());
		}
		else
		{
			return std::make_unique<HTTP::Entity::T> (
			    std::make_unique<IO::Vector::T> ());
		}
	}
}
