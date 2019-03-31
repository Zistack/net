template <typename Request, typename Response, typename Interface>
template <typename InputStream, typename OutputStream>
void
T <Request, Response, Interface>::run
(
	InputStream && input_stream,
	OutputStream && output_stream
)
{
	Failure::ExceptionStore::T exception_store;

	{
		Thread::Nursery::T nursery (exception_store);

		nursery.add
		(
			this -> input,
			& Input::T <Request, Response, Interface>::
				template run <InputStream>,
			this -> input,
			* this,
			std::forward <InputStream> (input_stream)
		);

		nursery.run
		(
			this -> output,
			& Output::T <Response, Interface>::template run <OutputStream>,
			this -> output,
			*this,
			std::forward <OutputStream> (output_stream)
		);
	}

	exception_store . poll ();
}
