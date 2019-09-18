template <typename Stage>
using T = Thread::Nursery::Collection::T <false, InnerStageExecutor::T <Stage>>;
