
template<class T>
class myVector
{
	T* vektor;
	int currSize;
	int allSize;
public:
	myVector();
	myVector(long leng);
	~myVector();
	T first();
	T last();
	int size()const noexcept;
	void add(const T&);
	void remove(int);
	T get(int);
};

template <class T>
myVector<T>::myVector()
{
	this->vektor = new T[10];
	this->currSize = 0;
	this->allSize = 10;
}

template <class T>
myVector<T>::myVector(long leng)
{
	this->vektor = new T[leng];
	this->currSize = 0;
	this->allSize = leng;
}

template <class T>
myVector<T>::~myVector()
{
	delete[] this->vektor;
}

template <class T>
 T myVector<T>::first()
{
	if (this->vektor)
		return this->vektor[0];
}

 template <class T>
 T myVector<T>::last()
 {
	 return this->vektor[currSize - 1];
 }

 template <class T>
 int myVector<T>::size() const noexcept
 {
	 return this->currSize;
 }

 template <class T>
 void myVector<T>::add(const T& item) {
	 if (this->allSize <= this->currSize + 1) {
		 T* temp = new T[this->allSize + 10];
		 for (int i = 0; i < this->currSize; i++) {
			 temp[i] = this->vektor[i];
		 }
		 delete[] this->vektor;
		 this->vektor = temp;
		 this->allSize += 10;
	 }
	 this->vektor[this->currSize] = item;
	 this->currSize++;
 }

 template <class T>
 void myVector<T>::remove(int index)
 {
	 for (int i = index; i < this->currSize; i++)
	 {
		 this->vektor[i] = this->vektor[i + 1];
	 }
	 currSize--;
 }

 template <class T>
 T myVector<T>::get(int index)
 {
	 if (this->currSize > index and index > -1)
		 return this->vektor[index];
	 else return -1;
 }

 template <class T, class D>
 void increm_1(T& i, const D delta) 
 {                                         
	 i += t(delta);
 };

 template <class T>
 void increm_1(T& i)
 {
	 i += t(1);
 };


int main()
{
	
}

