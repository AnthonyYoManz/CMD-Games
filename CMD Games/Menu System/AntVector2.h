#ifndef ANT_VECTOR_2D
#define ANT_VECTOR_2D

namespace ant
{
	template <class t_Type> class Vector2
	{
	public:
		t_Type x;
		t_Type y;

		Vector2() = default;
		/*Sets x and y to the provided values*/
		Vector2(t_Type _x, t_Type _y)
		{
			set(_x, _y);
		};
		/*Sets x and y to the provided values*/
		void set(t_Type _x, t_Type _y)
		{
			x = _x;
			y = _y;
		}
	};

	using Vector2i = Vector2 < int >;
	using Vector2u = Vector2 < unsigned int > ;
	using Vector2f = Vector2 < float >;
}

#endif