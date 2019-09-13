struct T : Spec::T
{
	using Value = T;

	using Spec::T::T;

	const std::string &
	certificateFilename () const;

	std::string &
	certificateFilename ();

	const std::string &
	privateKeyFilename () const;

	std::string &
	privateKeyFilename ();
};
