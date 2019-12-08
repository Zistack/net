template <typename InputStream, typename Stage, typename OutputStream>
using T = Thread::Nursery::Aggregate::T
<
	false,
	FirstStageExecutor::T <InputStream, Stage> &,
	InnerCancellableSlot::T <Stage> &,
	LastStageExecutor::T <Stage, OutputStream> &
>;
