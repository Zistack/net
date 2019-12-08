template <typename InputStream, typename Stage, typename OutputStream>
struct T
{
	T (InputStream input_stream, const Stage & stage, OutputStream output_stream);

	void
	run ();

	void
	cancel ();

	~T () = default;

private:

	InputStream m_input_stream;
	const Stage & m_stage;
	OutputStream m_output_stream;
};

template <typename InputStream, typename Stage, typename OutputStream>
T (InputStream && input_stream, const Stage & stage, OutputStream && output_stream) ->
	T <InputStream, Stage, OutputStream>;
