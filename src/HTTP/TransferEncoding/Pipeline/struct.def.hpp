template <typename Stage>
struct T
{
	T () = default;

	void
	addBoundedIdentity (size_t size);

	template
	<
		typename InputStream,
		typename OutputStream,
		typename CancellableSlot
	>
	void
	recode
	(
		InputStream && input_stream,
		OutputStream && output_stream,
		CancellableSlot & recode_slot
	) const;

	~T () = default;

protected:

	std::list <Stage> m_stages;
};
