template <typename Interface, typename Request, typename Response>
template <typename InputStream, typename OutputStream>
void
T <Interface, Request, Response>::run
(
	InputStream && input_stream,
	OutputStream && output_stream
)
{
	Thread::Nursery::Aggregate::T nursery
	(
		std::forward_as_tuple
		(
			this -> input (),
			[&] ()
			{
				this -> input () . run
				(
					std::forward <InputStream> (input_stream)
				);
			}
		),
		std::forward_as_tuple
		(
			this -> output (),
			[&] ()
			{
				this -> output () . run
				(
					std::forward <OutputStream> (output_stream)
				);
			}
		)
	);
}
