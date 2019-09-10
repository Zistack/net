template <typename Dispatcher>
template <typename ... DispatcherArguments>
T <Dispatcher>::T
(
	const Config::T & config,
	const URI::T & requested_resource,
	DispatcherArguments && ... dispatcher_arguments
)
:	Input::T <Interface::T <Dispatcher>, Dispatcher>
	(
		config . getInputTimeout (),
		config . getCloseTimeout (),
		config . getTempFileThreshhold (),
		requested_resource,
		std::forward <DispatcherArguments> (dispatcher_arguments) ...
	),
	Output::T <Interface::T <Dispatcher>>
	(
		config . getOutputTimeout (),
		config . getChunkSize ()
	)
{
}
