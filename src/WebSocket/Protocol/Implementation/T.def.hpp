template <typename Dispatcher>
template <typename ... Arguments>
T <Dispatcher>::T (const Config::T & config, Arguments && ... arguments)
:	Input::T <Interface::T <Dispatcher>, Dispatcher>
	(
		config . getInputTimeout (),
		config . getCloseTimeout (),
		config . getTempFileThreshhold (),
		std::forward <Arguments> (arguments) ...
	),
	Output::T <Interface::T <Dispatcher>>
	(
		config . getOutputTimeout (),
		config . getChunkSize ()
	)
{
}
