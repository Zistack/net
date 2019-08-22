template <typename Visitor>
auto
T::withWriterAt (Visitor && visitor, uint64_t position)
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
