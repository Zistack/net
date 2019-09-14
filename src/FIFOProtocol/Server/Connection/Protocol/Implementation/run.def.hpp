template <typename Request, typename Response, typename Details>
template <typename InputStream, typename OutputStream>
void
T <Request, Response, Details>::run
(
	InputStream && input_stream,
	OutputStream && output_stream
)
{
	Failure::ExceptionStore::T exception_store;

	{
		Thread::Nursery::T nursery (exception_store);

		nursery . add
		(
			this -> input (),
			& Input::
				T
				<
					Interface::T <Request, Response, Details>,
					Request,
					Response,
					Details
				>::
				template run <InputStream>,
			& this -> input (),
			std::forward <InputStream> (input_stream)
		);

		nursery . run
		(
			this -> output (),
			& Output::
				T
				<
					Interface::T <Request, Response, Details>,
					Response,
					Details
				>::
				template run <OutputStream>,
			& this -> output (),
			std::forward <OutputStream> (output_stream)
		);
	}

	exception_store . poll ();
}
