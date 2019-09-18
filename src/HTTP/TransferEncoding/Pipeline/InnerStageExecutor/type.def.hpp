template <typename Stage>
using T = StageExecutor::T
<
	decltype
	(
		IO::Blocking::InputStream::T
		(
			std::declval <IO::Pipe::T> () . reciever ()
		)
	),
	Stage,
	decltype
	(
		IO::Blocking::OutputStream::T
		(
			std::declval <IO::Pipe::T> () . sender ()
		)
	)
>;

