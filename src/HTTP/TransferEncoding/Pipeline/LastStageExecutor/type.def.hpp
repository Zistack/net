template <typename Stage, typename OutputStream>
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
	OutputStream
>;
