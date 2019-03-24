template <typename Scopable>
T <Scopable>::~T ()
{
	if (this -> scopable)
	{
		this -> exception_store -> tryStore
		(
			[this] () { this -> scopable -> close (); }
		);
	}
}
