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
			[&] ()
			{
				this -> input () . run
				(
					std::forward <InputStream> (input_stream)
				);
			}
		);

		nursery . run
		(
			this -> output (),
			[&] ()
			{
				this -> output () . run
				(
					std::forward <OutputStream> (output_stream)
				);
			}
		);
	}

	exception_store . poll ();
}
