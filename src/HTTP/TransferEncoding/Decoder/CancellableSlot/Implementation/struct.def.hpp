template
<
	typename InputStream,
	template <typename ...> typename WriterPackContainer,
	typename ... Writers
>
struct T <InputStream, WriterPackContainer <Writers ...>>
{
	using Type = Failure::CancellableSlot::T
	<
		Pipeline::StageExecutor::T <InputStream, Stage::T, Writers, false> ...,
		Thread::Nursery::T
	>;
};
