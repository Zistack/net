template <typename Visitor>
auto
T::withWriterAt (Visitor && visitor, size_t position)
{
	return std::visit
	(
		[&] (auto && data)
		{
			return visitor
			(
				IO::Util::ensureBlocking (data . writerAt (position))
			);
		},
		this -> m_data
	);
}
