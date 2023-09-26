#include <iostream>
using namespace std;

class Matrix
{
    int **arr;
    int r;
    int c;

public:
    Matrix()
    {
        arr = new int *[3];
        for (int r = 0; r < 3; r++)
            arr[r] = new int[3];
    }
    Matrix(int row, int col)
    {
        this->r = row;
        this->c = col;
        arr = new int *[row];
        for (int r = 0; r < row; r++)
        {
            arr[r] = new int[col];
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < this->r; i++)
        {
            delete arr[i];
            
        }
        delete[] arr;
        
    }

    void accept()
    {
        for (int r = 0; r < this->r; r++)
        {
            for (int c = 0; c < this->c; c++)
            {
                int val;
                cout << "Enter arr[" << r << "]"
                     << "[" << c << "] value ";
                cin >> this->arr[r][c];
            }
        }
    }
    void print()
    {
        cout<<"MATRIX" <<endl;
        for (int r = 0; r < this->r; r++)
        {
            for (int c = 0; c < this->c; c++)
            {
                cout << arr[r][c] << " ";
            }
            cout<<endl;
        }
    }

    void Add(Matrix *ptr1, Matrix *ptr2)
    {
        if (ptr1->r == ptr2->r && ptr1->c == ptr2->c)
        {

            for (int i = 0; i < ptr1->r; i++)
            {
                for (int j = 0; j < ptr1->c; j++)
                {
                    cout << (ptr1->arr[i][j] + ptr2->arr[i][j]) << " ";
                }
                cout << endl;
            }
        }
        else
            cout << "Given dimension is invalid! ";
    }
    void subtract(Matrix *ptr1, Matrix *ptr2)
    {
        if (ptr1->r == ptr2->r && ptr1->c == ptr2->c)
        {

            for (int i = 0; i < ptr1->r; i++)
            {
                for (int j = 0; j < ptr1->c; j++)
                {
                    cout << (ptr1->arr[i][j] - ptr2->arr[i][j]) << " ";
                }
                cout << endl;
            }
        }
        else
            cout << "Given dimension is invalid! ";
    }

    // void multiply(Matrix *ptr1,Matrix *ptr2){
    //      if (ptr1->r == ptr2->r && ptr1->c == ptr1->c)
    //     {


    //     }
    //     else
    //     cout<<"Invalid Dimension Entered";


    // }
    void multiply(Matrix *ptr1, Matrix *ptr2)
    {
        if (ptr1->c == ptr2->r)
        {
            this->r = ptr1 ->r;
            this ->c = ptr2 ->c;

            for (int i = 0; i < ptr1->r; i++)
            {
                for (int j = 0; j < ptr2->c; j++)
                {
                    for (int k = 0; k < ptr1->c; k++)
                    {
                        this-> arr[i][j] = this-> arr[i][j] + ptr1->arr[i][k] * ptr2->arr[k][j];
                    }
                }
            }
            
            cout<< "Multiplication: " <<endl;
            for (int i = 0; i < this->r; i++)
            {
                for (int j = 0; j < this->c; j++)
                {
                    /* code */
                    cout<<arr[i][j]<<"\t";
                }
                cout<< endl; 
            }
        }
        else
            cout << "Dimensions are not compatible";
    }


    void transpose(Matrix *ptr1)
    {
        this->c = ptr1 -> r;
        this -> r = ptr1 ->c;
        for (int i = 0; i < ptr1->c; i++)
        {
            for(int j = 0 ; j< ptr1->r;j++){

               this-> arr[i][j] = ptr1-> arr[j][i];

            }
        }
        cout<< "Transpose: "<<endl;
        for (int  i = 0; i < this->r; i++)
        {
            for (int j = 0; j < this->c; j++)
            {
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
            
        }
        
    }
};

int main()
{
    cout << "Enter matrix dimension X and Y" << endl;
    int x, y;
    cin >> x >> y;
    // Matrix m1;
    Matrix m2(x, y);
    m2.accept();
    m2.print();

    cout << "Enter matrix dimension X and Y" << endl;
    int p, q;
    cin >> p >> q;

    Matrix m3(p, q);
    m3.accept();
    m3.print();

    Matrix m4(x,q);
    // m4.Add(&m2, &m3);
    // m4.subtract(&m2,&m3);
    m4.multiply(&m2, &m3);
    // m4.print();

    
    // m4.transpose(&m2);
}