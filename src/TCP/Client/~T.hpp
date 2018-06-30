T::~T ()
{
	delete this -> signal;
	delete this -> socket;
}
