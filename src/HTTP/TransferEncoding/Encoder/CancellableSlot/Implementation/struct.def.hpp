template
<
	typename OutputStream,
	template <typename ...> typename ReaderPackContainer,
	typename ... Readers
>
struct T <OutputStream, ReaderPackContainer <Readers ...>>
{
	using Type = Failure::CancellableSlot::T
	<
		Pipeline::StageExecutor::T <Readers, Stage::T, OutputStream, false> ...,
		Thread::Nursery::T
	>;
};
