struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const URI::Path::T &
	certificateFilename () const;

	URI::Path::T &
	certificateFilename ();

	const URI::Path::T &
	privateKeyFilename () const;

	URI::Path::T &
	privateKeyFilename ();
};
