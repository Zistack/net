template <typename InputStream, typename Stage, typename OutputStream>
struct T <InputStream, Stage, OutputStream, false>
:	Implementation::T <InputStream, Stage, OutputStream>
{
	using Implementation::T <InputStream, Stage, OutputStream>::T;
};

template <typename InputStream, typename Stage, typename OutputStream>
T (InputStream && input_stream, Stage & stage, OutputStream && output_stream) ->
	T <InputStream, Stage, OutputStream, false>;

template <typename InputStream, typename Stage, typename OutputStream>
struct T <InputStream, Stage, OutputStream, true>
:	Implementation::T <InputStream, Stage, OutputStream>
{
	T
	(
		InputStream input_stream,
		Stage & stage,
		OutputStream output_stream,
		IO::Pipe::T && pipe
	);

	void
	run ();

	~T () = default;

private:

	IO::Pipe::T pipe;
};

template <typename InputStream, typename Stage, typename OutputStream>
T
(
	InputStream && input_stream,
	Stage & stage,
	OutputStream & output_stream,
	IO::Pipe::T && pipe
) -> T <InputStream, Stage, OutputStream, true>;
