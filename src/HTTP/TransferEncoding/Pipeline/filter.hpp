void
T::filter (IO::Interface::InputStream::T & input_stream,
    IO::CancelSignal::T * input_cancel_signal,
    IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T * output_cancel_signal,
    Failure::CancelScope::T & cancel_scope)
{
	if (this->stages.size () == 1)
	{
		std::unique_ptr<TransferEncoding::T> stage =
		    std::move (stages.front ());
		stages.pop_front ();

		Failure::CancelScope::Bind::T input_cancel_binding;
		Failure::CancelScope::Bind::T output_cancel_binding;

		if (input_cancel_signal)
		{
			input_cancel_binding = Failure::CancelScope::Bind::T input_cancel_binding (cancel_scope, *input_cancel_signal);
		}

		if (output_cancel_signal)
		{
			output_cancel_binding = Failure::CancelScope::Bind::T output_cancel_binding (cancel_scope, *output_cancel_binding);
		}

		stage . filter (input_stream, output_stream);
	}
	else
	{
		std::unique_ptr<TransferEncoding::T> first_stage =
		    std::move (stages.front ());
		std::unique_ptr<TransferEncoding::T> last_stage =
		    std::move (stages.back ());
		stages.pop_front ();
		stages.pop_back ();

		Failure::ExceptionStore::T exception_store;

		{
			Thread::Nursery::T nursery (exception_store);
			Failure::CancelScope::Bind::T nursery_binding (
			    cancel_scope, nursery);

			std::shared_ptr<IO::Pipe::T> next_pipe (new IO::Pipe::T ());

			std::unique_ptr<IO::CancelSignal::T> first_stage_cancel_signal;
			if (!input_cancel_signal)
			{
				first_stage_cancel_signal =
				    std::make_unique<IO::CancelSignal::T> ();
				input_cancel_signal = first_stage_cancel_signal.get ();
			}

			nursery.add (
			    [next_pipe,
			        &input_stream,
			        &input_cancel_signal (*input_cancel_signal),
			        &stage (*stage)]() {
				    IO::Blocking::OutputStream::T output_stream (
				        next_pipe->outputStream (), input_cancel_signal);

				    stage . filter (input_stream, output_stream);

				    next_pipe->shutdown ();
			    },
			    input_cancel_signal);

			std::shared_ptr<IO::Pipe::T> previous_pipe = next_pipe;

			for (auto & stage : this->stages)
			{
				next_pipe = std::make_unique<IO::Pipe::T> ();

				std::unique_ptr<IO::CancelSignal::T> stage_cancel_signal (
				    new IO::CancelSignal::T ());
				Failure::CancelScope::T * stage_cancel_signal_ptr =
				    stage_cancel_signal.get ();

				nursery.add (
				    [previous_pipe,
				        next_pipe,
				        stage_cancel_signal (std::move (stage_cancel_signal)),
				        &stage (*stage)]() {
					    IO::Blocking::InputStream::T input_stream (
					        previous_pipe->inputStream (),
					        *stage_cancel_signal);
					    IO::Blocking::OutputStream::T output_stream (
					        next_pipe->outputStream (), *stage_cancel_signal);

					    stage . filter (input_stream, output_stream);

					    next_pipe->shutdown ();
				    },
				    stage_cancel_signal_ptr)

				    previous_pipe = next_pipe;
			}

			next_pipe = nullptr;

			std::unique_ptr<IO::CancelSignal::T> last_stage_cancel_signal;
			if (!output_cancel_signal)
			{
				last_stage_cancel_signal =
				    std::make_unique<IO::CancelSignal::T> ();
				output_cancel_signal = last_stage_cancel_signal.get ();
			}

			nursery.run (
			    [last_pipe,
			        &output_stream,
			        &output_cancel_signal (*output_cancel_signal),
			        &stage (*stage)]() {
				    IO::Blocking::InputStream::T input_stream (
				        previous_pipe->inputStream (), output_cancel_signal);

				    stage . filter (input_stream, output_stream);
			    },
			    output_cancel_signal);
		}

		exception_store.poll ();
	}
}
