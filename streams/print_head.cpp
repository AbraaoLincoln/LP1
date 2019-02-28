#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;
 
/* *!
7 * Print the table ’s header to the terminal ( std :: cout ).
8 * @param fields_ Reference to the list of header fields to be printed .
9 */
 void printHeader ( const std :: vector < std :: string > & fields_ ) {
    // TODO
    ostringstream line, head;

    for(const auto s : fields_)
    {
        line << "+" << setw(s.size() + 3) << setfill('-');
        head << "| " << s << " ";
    }
    line << "+";
    head << "|";

    cout << line.str() << endl;
    cout << head.str() << endl;
    cout << line.str() << endl;


    /*
    for(int i{0u}; i < fields_.size(); i++)
    {
        cout << "+" << setw(fields_[i].size() + 3) << setfill('-');
    }
    cout << "+";
    cout << endl;

    cout << "| ";
    for(int i{0u}; i < fields_.size(); i++)
    {
        cout << fields_[i] << " | ";
    }
    //cout << " |";
    cout << endl;

    for(int i{0u}; i < fields_.size(); i++)
    {
        cout << "+" << setw(fields_[i].size() + 3) << setfill('-');
    }
    cout << "+";
    cout << endl;
    */
 }

 int main () {
    std::vector <std::string> fieldNames = { "ITEM", "QUANTIDADE", "VALOR UNITARIO" };
    printHeader(fieldNames); // Imprimir cabecalho da tabela .
    return EXIT_SUCCESS ;
 }