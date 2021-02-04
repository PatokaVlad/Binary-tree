#include <iostream>
#include <vector>


using namespace std;

template <typename T>
class Tree
{
public:
    int LeftSize = 0, RightSize = 0;
    Tree(T Data);
    ~Tree();
    void Add(T Data);
    void SeeAll();
    bool FindElement(T Data);
private:
    T Data = NULL;
    Tree* Left = nullptr;
    Tree* Right = nullptr;
};

template<typename T>
Tree<T>::Tree(T NewData)
{
    Data = NewData;
    Tree* Left = nullptr;
    Tree* Right = nullptr;
}

template<typename T>
Tree<T>::~Tree()
{
    delete Left;
    delete Right;
}

template<typename T>
void Tree<T>::Add(T NewData)
{
    Tree* Current = this;
    if (Current->Data == NULL)
    {
        Data = NewData;
    }
    else
    {
        if (NewData < Data)
        {
            LeftSize++;
            if (Left == nullptr)
                Left = new Tree<T>(NewData);
            else
                Left->Add(NewData);
        }
        else
        {
            RightSize++;
            if (Right == nullptr)
                Right = new Tree<T>(NewData);
            else
                Right->Add(NewData);
        }
    }
}

template<typename T>
void Tree<T>::SeeAll()
{
    Tree* Current = this;
    cout << Current->Data << endl;
    if (Current->Left != nullptr)
        Current->Left->SeeAll();
    if (Current->Right != nullptr)
        Current->Right->SeeAll();

}

template<typename T>
bool Tree<T>::FindElement(T Data)
{
    Tree* Current = this;
    if (Current->Data == Data)
        return true;
    else
    {
        if (Current->Left != nullptr)
            if (Current->Left->FindElement(Data) == true)
                return true;
        if (Current->Right != nullptr)
            if (Current->Right->FindElement(Data) == true)
                return true;
    }
    return false;
}

int main()
{
    Tree<int> Root(NULL);

    int N = 0;

    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> Input(N);

    cout << "Input: " << endl;
    for (int i = 0; i < N; i++)
    {
        Input[i] = rand() % 10;
        cout << Input[i] << endl;
        Root.Add(Input[i]);
    }

    cout << "Output: " << endl;
    Root.SeeAll();

    cout << "Finding: " << endl;
    for (int i = 0; i < N; i++)
    {
        bool Do = Root.FindElement(Input[i]);
        if (Do == true)
            cout << "Element " << Input[i] << " find successfully!" << endl;
        else
            cout << "Element " << Input[i] << " not find!" << endl;
    }

    return 0;
}