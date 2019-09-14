struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const std::string &
	certificateFilename () const;

	std::string &
	certificateFilename ();

	const std::string &
	privateKeyFilename () const;

	std::string &
	privateKeyFilename ();
};
