#include <iostream>
#include <string>
using namespace std;

class Flower{

public:


	Flower()
	: m_Name( "" ),
	  m_Color( "" ),
	  m_Price( 0 ),
	  m_IsPerfumed( false ),
	  m_IsOnSale( false )
	{
	}

	Flower( string name, string color, float price, bool perfumeState = false, bool saleState = false )
	: m_Name( name ),
	  m_Color( color ),
	  m_Price( price ),
	  m_IsPerfumed( perfumeState ),
	  m_IsOnSale( saleState )
	{
	}

	float getPrice() const {
		if ( m_IsOnSale )
			return m_Price / 2;
		else
			return m_Price;
	}

	bool isPerfumed() const {
		return m_IsPerfumed;
	}

	friend ostream& operator<< ( ostream &output, const Flower &obj ){
		output << obj.m_Name << " " << obj.m_Color << " "
			   << obj.m_IsPerfumed << ", " << "Price: "
			   << obj.m_Price << " Rs. " << endl;
		return output;
	}

	bool operator== ( const Flower &obj ) const {
		if (( m_Name == obj.m_Name ) &&
			( m_Price == obj.m_Price ) &&
		    ( m_IsPerfumed == obj.m_IsPerfumed )) {
			return true;
		}
		else
			return false;
	}

private:

	string m_Name;
	string m_Color;
	float m_Price;
	bool m_IsPerfumed;
	bool m_IsOnSale;


};

class Bouquet{

public:

	Bouquet ()
	: m_Array( nullptr ),
	  m_Size( 0 )
	{
	}

	Bouquet ( const Bouquet &rhs ){
		m_Size = rhs.m_Size;
		m_Array = new Flower[m_Size];

		for ( int i = 0; i < m_Size; ++i ){
			m_Array[i] = rhs.m_Array[i];
		}
	}

	bool isPerfumed() const {
		for ( int i = 0; i < m_Size; ++i ){
			if ( m_Array[i].isPerfumed() )
				return true;
		}
		return false;
	}

	float getPrice() const {
		float total = 0;

		for ( int i = 0; i < m_Size; ++i ){
			total += m_Array[i].getPrice();
		}
		return isPerfumed() ? total * 2 : total;
	}

	friend ostream& operator<< ( ostream &output, const Bouquet &obj ){
		if ( !obj.m_Array ){
			output << "Still no flower in the bouquet" << endl;
			return output;
		}
		else{
			if ( obj.isPerfumed() )
				output << "Perfumed bouquet composed of:\n" << endl;
			else
				output << "Non-Perfumed bouquet composed of:\n" << endl;

			for ( int i = 0; i < obj.m_Size; ++i ){
				output << obj.m_Array[i];
			}

			output << "\nTotal Price: " << obj.getPrice() << " Rs." << endl;
			return output;
		}
	}

	const Bouquet& operator= ( const Bouquet& rhs ){
		delete[] m_Array;
		m_Size = rhs.m_Size;
		m_Array = new Flower[m_Size];

		for ( int i = 0; i < m_Size; ++i ){
			m_Array[i] = rhs.m_Array[i];
		}
		return *this;
	}

	Bouquet& operator+= ( const Flower& flowerObj ){
		if ( m_Size > 0 ){
			Bouquet temp = *this;

			delete[] m_Array;
			++m_Size;
			m_Array = new Flower[m_Size];

			for ( int i = 0; i < temp.m_Size; ++i ){
				m_Array[i] = temp.m_Array[i];
			}
			m_Array[m_Size - 1] = flowerObj;
			return *this;
		}
		else if ( m_Size == 0 ){
			++m_Size;
			m_Array = new Flower[m_Size];
			m_Array[0] = flowerObj;
		}
	}

	Bouquet& operator-= ( const Flower &flowerObj ){
		if ( m_CountFlower( flowerObj ) == 0 or m_Size == 0 ){
			return *this;
		}
		else{
			int noOfFlowers = m_CountFlower( flowerObj );
			Bouquet temp = *this;

			delete[] m_Array;
			m_Size -= noOfFlowers;
			m_Array = new Flower[m_Size];

			for ( int i = 0; i < temp.m_Size; ++i ){
				if ( temp.m_Array[i] == flowerObj ){
					continue;
				}
				else
					m_Array[i] = temp.m_Array[i];
			}
		}
		return *this;
	}

	Bouquet operator- ( const Flower &flowerObj ){
		if ( m_CountFlower( flowerObj ) == 0 or m_Size == 0 ){
			return *this;
		}
		else{
			Bouquet temp = *this;
			temp -= flowerObj;
			return temp;
		}
	}

	Bouquet operator+ ( const Flower& flowerObj ){
		Bouquet temp = *this;
		temp += flowerObj;
		return temp;
	}


	~Bouquet(){
		m_deleteArray();
	}

private:

	Flower *m_Array;
	int m_Size;

	int m_CountFlower( const Flower& flower ){
		int total = 0;

		for ( int i = 0; i < m_Size; ++i ){
			if ( m_Array[i] == flower )
				++total;
		}
		return total;
	}

	void m_deleteArray(){
		delete[] m_Array;
	}


};


int main() {

	Flower r1( "Rose", "Yellow", 1.5 );
	Flower r2( "Rose", "Yellow", 3.0, true);
	Flower r3( "Rose", "Red", 2.0, true, true);

	Bouquet B1;
	B1 += r1;
	B1 += r2;


	Bouquet B2;

	B2 = B1 - r3;;
	cout << B2;


}
