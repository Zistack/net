template <typename InputStream, typename Stage>
using T = StageExecutor::T
<
	InputStream,
	Stage,
	decltype
	(
		IO::Blocking::OutputStream::T
		(
			std::declval <IO::Pipe::T> () . sender ()
		)
	)
>;
