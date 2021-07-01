#include "FoodType.h"
#include "Przepisy.h"
void wypisz_vector_str_counted(vector<string>x)
{
    for (int i = 0; i < x.size(); i++)
        cout << i + 1 << "." << x[i] << endl;
}

int main()
{
    //FoodType *food;
    //food = new WegeType(1);
    //food->ingredients();
    Przepisy przepis;
    przepis.find_przepis();
    

}