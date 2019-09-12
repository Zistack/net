struct T
{
	template <typename InputStream>
	T (InputStream && input_stream, uint64_t length);

	T
	(
		uint16_t status_code = 1000,
		const std::optional <std::string> & reason = std::nullopt
	);

	uint64_t
	length () const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	~T () = default;

private:

	uint16_t m_status_code;
	std::optional <std::string> m_reason;
};
