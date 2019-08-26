template <typename Dispatcher>
template <typename InputStream, typename OutputStream>
void
T <Dispatcher>::run (InputStream && input_stream, OutputStream && output_stream)
{
	Failure::ExceptionStore::T exception_store;

	{
		Thread::Nursery::T nursery (exception_store);

		nursery . add
		(
			this -> input (),
			& Input::
				T <Interface::T <Dispatcher>, Dispatcher>::
				template run <InputStream>,
			& this -> input (),
			std::forward <InputStream> (input_stream)
		);

		nursery . run
		(
			this -> output (),
			& Output::
				T <Interface::T <Dispatcher>>::
				template run <OutputStream>,
			& this -> output (),
			std::forward <OutputStream> (output_stream)
		);
	}

	exception_store . poll ();
}
