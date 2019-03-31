template <typename Request, typename Response, typename Interface>
template <typename InputStream, typename OutputStream>
void
T <Request, Response, Interface>::run
(
	InputStream && input_stream,
	OutputStream && output_stream
)
{
	{
		Thread::Nursery::T nursery;

		nursery.add
		(
			this -> input,
			& Input::T <Response, Interface>::template run<InputStream>,
			& this -> input,
			std::forward <InputStream> (input_stream)
		);

		nursery.run
		(
			this -> output,
			& Output::T <Request, Interface>::template run<OutputStream>,
			& this -> output,
			std::forward <OutputStream> (output_stream)
		);
	}
}
