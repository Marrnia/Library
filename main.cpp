#include <iostream>
using std::cout;

int main() {
    
    cout << "<command>";
    cout.width(23);
    cout << "<123>\n";
    cout << "<command>";
    cout.width(23);
    cout << "123\n";
    return 0;
}