template <typename Dispatcher>
template <typename ... Arguments>
T <Dispatcher>::T (const Config::T & config, Arguments && ... arguments)
:	input
	(
		config . getInputTimeout (),
		config . getCloseTimeout (),
		config . getTempFileThreshhold (),
		this -> output,
		std::forward <Arguments> (arguments) ...
	),
	output (config . getOutputTimeout (), config . getChunkSize ())
{
}
