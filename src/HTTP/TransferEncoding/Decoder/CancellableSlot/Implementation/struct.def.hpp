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
		Pipeline::StageExecutor::T <InputStream, Stage::T, Writers> ...,
		Pipeline::Nursery::T <InputStream, Stage::T, Writers> ...
	>;
};
