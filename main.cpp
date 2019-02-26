#include "avl.hh"  
#include <cstdlib>
#include <ctime>
//including .cpp to avoid linking errors caused by templates
#include "avl.cpp"

using namespace std;

//type of avl tree created in main
typedef int type;

void displayMenu(void)
{
    cout << "\n";
    cout << "a -> add element\n";
    cout << "d -> remove element\n";
    cout << "p -> display preorder\n";
    cout << "i -> display inorder\n";
    cout << "j -> display inorder with height\n";
    cout << "r -> display postorder\n";
    cout << "h -> display height\n";
    cout << "o -> display root value\n";
    cout << "t -> test\n";
    cout << "k -> clear tree\n";
    cout << "q -> exit\n\n";
}

void displayTestMenu(void)
{
    cout << "\n";
    cout << "1 -> Increasing insertion test\n";
    cout << "2 -> Decreasing insertion test\n";
    cout << "3 -> Random insertion test\n";
    cout << "4 -> Increasing deletion test\n";
    cout << "5 -> Decreasing deletion test\n";
    cout << "6 -> Random deletion test\n";
    cout << "9 -> Return\n";
}

void increasingInsertionTest(avl<type> &tree, int number)
{
    for(int i=0; i<number; i++)
        tree.insert(i);
}

void decreasingInsertionTest(avl<type> &tree, int number)
{
    for(int i=0; i<number; i++)
        tree.insert(-i);
}

void randomInsertionTest(avl<type> &tree, int number)
{
    srand((unsigned)time(0));

    for(int i=0; i<number; i++)
        tree.insert(rand()%(10 * number));
}

void increasingDeletionTest(avl<type> &tree, int number)
{
    for(int i=0; i<number; i++)
        tree.remove(i);
}

void decreasingDeletionTest(avl<type> &tree, int number)
{
    for(int i=0; i<number; i++)
        tree.remove(-i);
}

void randomDeletionTest(avl<type> &tree, int number)
{
    srand((unsigned)time(0));

    for(int i=0; i<number; i++)
        tree.remove(rand()%(10 * number));
}

void test(avl<type> &tree)
{
    
    char option;
    int number;

    do
    {
        displayTestMenu();
        cin >> option;
        switch(option)
        {
            case '1':
                cout << "How many numbers: \n";
                cin >> number;
                increasingInsertionTest(tree, number);
            break;
            case '2':
                cout << "How many numbers: \n";
                cin >> number;
                decreasingInsertionTest(tree, number);
            break;
            case '3':
                cout << "How many numbers: \n";
                cin >> number;
                randomInsertionTest(tree, number);
            break;
            case '4':
                cout << "How many numbers: \n";
                cin >> number;
                increasingDeletionTest(tree, number);
            break;
            case '5':
                cout << "How many numbers: \n";
                cin >> number;
                decreasingDeletionTest(tree, number);
            break;
            case '6':
                cout << "How many numbers: \n";
                cin >> number;
                randomDeletionTest(tree, number);
            break;
            case '9': break;
            default: cout << "No such option\n"; break;
        }

    } while(option != '9');
}

int main(void)
{
    type element;
    char option;
    avl<type> tree;
    
    do
    {
        displayMenu();
        cin >> option;
        switch(option)
        {
            case 'a': 
                cout << "Number: \n"; 
                cin >> element; 
                tree.insert(element); 
            break;
            case 'd': 
                cout << "Number: \n";
                cin >> element; 
                tree.remove(element); 
            break;
            case 'p': tree.displayPreorder(); break;
            case 'i': tree.displayInorder(); break;
            case 'j': tree.displayHeight(); break;
            case 'r': tree.displayPostorder(); break;
            case 'h': tree.displayTreeHeight(); break;
            case 'o': tree.displayRootValue(); break;
            case 't': test(tree); break;
            case 'k': tree.clearTree(); break;
            case 'q': tree.clearTree(); break;
            default: cout << "No such option\n"; break;
        }

    } while(option != 'q');  
}