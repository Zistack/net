struct T
{
	T ();

	T (uint64_t entity_size, uint64_t temp_file_threshhold);

	T (T && other) = default;

	T &
	operator = (T && other) = default;

	uint64_t
	size () const;

	template <typename Visitor>
	auto
	withReader (Visitor && visitor);

	template <typename Visitor>
	auto
	withReaderAt (Visitor && visitor, uint64_t position);

	template <typename Visitor>
	auto
	withWriter (Visitor && visitor);

	template <typename Visitor>
	auto
	withWriterAt (Visitor && visitor, uint64_t position);

	~T () = default;

private:

	static Data::T
	newData (uint64_t entity_size, uint64_t temp_file_threshhold);

	Data::T m_data;
};
