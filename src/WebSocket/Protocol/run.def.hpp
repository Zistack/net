template <typename Interface>
template <typename InputStream, typename OutputStream>
void
T <Interface>::run (InputStream && input_stream, OutputStream && output_stream)
{
	Failure::ExceptionStore::T exception_store;

	{
		Thread::Nursery::Aggregate::T nursery
		(
			exception_store,
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

	exception_store . poll ();
}
