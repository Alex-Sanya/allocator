#include "queue.hpp"
#include "octagon.hpp"
#include <algorithm>
using namespace std;
const size_t ALLOCATOR_SIZE = 10000;
auto main() -> int
{
    Myqueue<Octagon<int>, my_allocator<Octagon<int>, ALLOCATOR_SIZE> > queue;
    cout << "1 - Add octagon to collection." << endl;
    cout << "2 - Remove octagon from collection. " << endl;
    cout << "3 - Displays all octagons in the collection. " << endl;
    cout << "4 - Exit " << endl;
    while (true) 
    {
        int choice;
        cout << "> ";
        cin >> choice;
        if (choice == 1) 
        {
            cout << "Enter the octagon (center coordinates and the radius vector of the circumscribed circle): ";
            pair<int, int> vx, vec;
            cin >> vx.first >> vx.second >> vec.first >> vec.second;
            Octagon<int> oct(vx, vec);
            cout << "Enter the add position: ";
            int pos;
            cin >> pos;
            try 
            {
                --pos;
                auto iter = queue.Begin();
                while (pos != 0) 
                {
                    ++iter;
                    --pos;
                }
                queue.Insert(iter, oct);
                cout << "The octagon has been added to the collection." << endl;
            }
            catch (std::exception& exception) 
            {
                cout << exception.what() << endl;
            }
        }
        else if (choice == 2) 
        {
            cout << "Enter the deletion position: ";
            int pos;
            cin >> pos;
            try 
            {
                --pos;
                auto iter = queue.Begin();
                while (pos != 0) 
                {
                    ++iter;
                    --pos;
                }
                queue.Erase(iter);
                cout << "The octagon has been removed from the collection." << endl;
            }
            catch (std::exception& exception) 
            {
                cout << exception.what() << endl;
            }
        }
        else if (choice == 3)
        {
            int count = 0;
            for_each(queue.Begin(),
                queue.End(),
                [&count](Octagon<int>& iter) 
                {
                    ++count;
                    cout << "Octagon #" << count << " : ";
                    iter.print();
                });
        }
        else if (choice == 4) 
            break;
        else 
            cout << "Wrong input!" << endl;
    }
}