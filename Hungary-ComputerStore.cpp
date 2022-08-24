#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <bits/stdc++.h>
#include <random>
#include <time.h>
#define HEAD "-65536"
#define TAIL "65536"
#include <cctype>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////
// function

struct Product
{
    int productQuantity;
    float productPrice;
    string productName, productID, productCategory, productBrand, product;
    Product *next;
};

typedef Product *Set;
Product *initProductNode(string v);
Set newSet(void);
int main();
void saveSet(Set set);
bool isIdExist(string id, Set a);
bool isItemNameExist(string name, Set a);
void addInfo(Set a);
string generateID(Set a);
void displayInstruction();
void displayAddInstruction();
void deleteProduct(Set product);
void deleteSet(int delID, Set set);
void sortSwap(Product a, Product b);
Set sortItems(Set a, int func);
Set sortInstructions(Set a);
Set addProduct(string product, Set s);
void loadItem(Set a);
Product *initLLNode(string pid, string pName, string pCar, string pBrand, float pPrice, int pQuantity);
void displayItem(Set a);
void editProduct(Set product);
void editSet(string itemID, Set product);
void searchMenu(Set a);
void searchItem(int choice, string data, Set a);

// function
////////////////////////////////////////////////////////////////////////////////////
// subfunction

string generateID(Set a)
{
    srand(time(0));
    string id = to_string((rand() % 9000) + 1000);

    if (isIdExist(id, a)) // if id is found
    {
        generateID(a);
    }

    return id;
}

bool isIdExist(string id, Set a)
{
    Product *temp;

    temp = a->next;

    while (temp != nullptr)
    {
        if (temp->productID == id)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

bool isItemNameExist(string name, Set a)
{
    Product *temp;

    temp = a->next;

    while (temp != nullptr)
    {
        if (temp->productName == name)
        {
            return false;
        }

        temp = temp->next;
    }

    return true;
}

// Swap function (Matthew Labial John)
void sortSwap(Product *a, Product *b)
{
    int productQuantity = a->productQuantity;
    float productPrice = a->productPrice;
    string productName = a->productName, productID = a->productID, productCategory = a->productCategory, productBrand = a->productBrand, product = a->product;

    a->product = b->product;
    a->productBrand = b->productBrand;
    a->productCategory = b->productCategory;
    a->productID = b->productID;
    a->productName = b->productName;
    a->productPrice = b->productPrice;
    a->productQuantity = b->productQuantity;
    b->product = product;
    b->productBrand = productBrand;
    b->productCategory = productCategory;
    b->productID = productID;
    b->productName = productName;
    b->productPrice = productPrice;
    b->productQuantity = productQuantity;

    a->next = b;
}

// Sorting function (Matthew Labial John)
Set sortItems(Set set, int func)
{
    Product *ptrone, *ptrtwo = NULL;
    int swapped;

    do
    {
        if (func == 1)
        {

            swapped = 0;
            ptrone = set->next;

            while ((ptrone->next != ptrtwo) && (ptrone && ptrone->next != NULL))
            {
                if (ptrone->productName > ptrone->next->productName)
                {
                    sortSwap(ptrone, ptrone->next);
                    swapped = 1;
                }
                ptrone = ptrone->next;
            }

            ptrtwo = ptrone;
        }
        else if (func == 2)
        {

            swapped = 0;
            ptrone = set->next;

            while ((ptrone->next != ptrtwo) && (ptrone && ptrone->next != NULL))
            {
                if (ptrone->productName < ptrone->next->productName)
                {
                    sortSwap(ptrone, ptrone->next);
                    swapped = 1;
                }
                ptrone = ptrone->next;
            }

            ptrtwo = ptrone;
        }
        else if (func == 3)
        {

            swapped = 0;
            ptrone = set->next;

            while ((ptrone->next != ptrtwo) && (ptrone && ptrone->next != NULL))
            {
                if (ptrone->productID > ptrone->next->productID)
                {
                    sortSwap(ptrone, ptrone->next);
                    swapped = 1;
                }
                ptrone = ptrone->next;
            }

            ptrtwo = ptrone;
        }
        else if (func == 4)
        {

            swapped = 0;
            ptrone = set->next;

            while ((ptrone->next != ptrtwo) && (ptrone && ptrone->next != NULL))
            {
                if (ptrone->productID < ptrone->next->productID)
                {
                    sortSwap(ptrone, ptrone->next);
                    swapped = 1;
                }
                ptrone = ptrone->next;
            }

            ptrtwo = ptrone;
        }
        else if (func == 5)
        {

            swapped = 0;
            ptrone = set->next;

            while ((ptrone->next != ptrtwo) && (ptrone && ptrone->next != NULL))
            {
                if (ptrone->productPrice > ptrone->next->productPrice)
                {
                    sortSwap(ptrone, ptrone->next);
                    swapped = 1;
                }
                ptrone = ptrone->next;
            }

            ptrtwo = ptrone;
        }
        else if (func == 6)
        {

            swapped = 0;
            ptrone = set->next;

            while ((ptrone->next != ptrtwo) && (ptrone && ptrone->next != NULL))
            {
                if (ptrone->productPrice < ptrone->next->productPrice)
                {
                    sortSwap(ptrone, ptrone->next);
                    swapped = 1;
                }
                ptrone = ptrone->next;
            }

            ptrtwo = ptrone;
        }
    } while (swapped);

    return set;
}

void addInfo(Set a)
{
    string itemId, itemName, category, brand, quantity, command;
    float price;
    Set item;

    displayAddInstruction();
    cout << "Please enter an instruction : ";
    cin >> command;

    if (command == "1")
    {
        cin.ignore();
        while (true)
        {
            cout << "Enter the name of item     : ";
            getline(cin, itemName);
            std::transform(itemName.begin(), itemName.end(), itemName.begin(),
                           [](unsigned char c)
                           { return tolower(c); });

            if (isItemNameExist(itemName, a)) // if name is not exist, break
            {
                break;
            }
            cout << "item exist, pls add a new item" << endl;
        }

        cout << "Enter the category of item : ";
        getline(cin, category);
        std::transform(category.begin(), category.end(), category.begin(),
                       [](unsigned char c)
                       { return tolower(c); });
        cout << "Enter the brand of item    : ";
        getline(cin, brand);
        std::transform(brand.begin(), brand.end(), brand.begin(),
                       [](unsigned char c)
                       { return tolower(c); });
        cout << "Enter the quantity of item : ";
        getline(cin, quantity);
        cout << "Enter the price of item    : RM";
        cin >> price;

        itemId = generateID(a);

        ostringstream change;
        change << fixed << setprecision(2) << price;
        string p = change.str();

        item = newSet();
        item = addProduct(quantity, item);
        item = addProduct(p, item);
        item = addProduct(brand, item);
        item = addProduct(category, item);
        item = addProduct(itemName, item);
        item = addProduct(itemId, item);

        item = sortItems(item, 1);
        saveSet(item);
        loadItem(a);
        addInfo(a);
    }
    else if (command == "0")
    {
        cout << endl;
        main();
    }
    else
    {
        cout << endl
             << "Wrong instruction... Please enter again" << endl
             << endl;
        addInfo(a);
    }
}

// Display Main menu Function  (Chew Zhi Peng)
void displayInstruction()
{
    cout << endl
         << "============================" << endl;
    cout << "Computer Store Management" << endl;
    cout << "============================" << endl;
    cout << "1. Add New Item" << endl;
    cout << "2. Edit Item" << endl;
    cout << "3. Delete Item" << endl;
    cout << "4. List Item Information" << endl;
    cout << "5. Searching for an Item" << endl;
    cout << "6. End program" << endl;
}

// Display Add menu function (Chew Zhi Peng)
void displayAddInstruction()
{
    cout << endl;
    cout << endl
         << "============================" << endl;
    cout << "Add New Item" << endl;
    cout << "============================" << endl
         << "1. Add a new Item" << endl;
    cout << "0. Back to main" << endl;
}

// Creating new set (Chew Zhi Peng)
Set newSet(void)
{
    Set temp;
    temp = initProductNode(HEAD);
    temp->next = initProductNode(TAIL);
    return temp;
}

// delete from file function (Matthew Labial John)
void deleteSet(int delID, Set set)
{
    int curID;

    ofstream replaceS;
    replaceS.open("itemList.csv");

    Product *temp;
    temp = set->next;

    while (temp && temp->next != NULL)
    {
        if (temp->productName != "")
        {
            stringstream upID(temp->productID);
            upID >> curID;

            if (delID != curID)
                replaceS << temp->productID << "," << temp->productName << "," << temp->productCategory << "," << temp->productBrand << "," << temp->productPrice << "," << temp->productQuantity << endl;
        }

        temp = temp->next;
    }

    cout << "Item deleted successful" << endl;
    replaceS.close();
}

// Delete Function (Matthew Labial John)
void deleteProduct(Set product)
{
    int opt;

    displayItem(product);

    cout << "=============================================================================================" << endl;
    cout << "Enter 0 to return main" << endl;
    cout << "Please enter the ID of item you wish to delete : ";
    cin >> opt;

    if (opt == 0)
    {
        main();
    }

    deleteSet(opt, product);

    main();
}

// Sorting instructions (Matthew Labial John)
Set sortInstructions(Set a)
{
    int opt;

    do
    {
        cout << endl
             << "============================" << endl
             << "Product Name Sorting Function" << endl
             << "============================" << endl
             << "Sort by" << endl
             << "1. Alphabetical Order" << endl
             << "2. ID" << endl
             << "3. Price" << endl
             << "0. Back to main" << endl
             << "Please enter an instruction : ";
        cin >> opt;
    } while (opt != 1 && opt != 2 && opt != 3 && opt != 0);

    if (opt == 1)
    {
        do
        {
            cout << endl
                 << "Sorting by Alphabetical Order" << endl
                 << "1. Ascending" << endl
                 << "2. Descending" << endl
                 << "Please enter an instruction : ";
            cin >> opt;
        } while (opt != 1 && opt != 2);

        if (opt == -1)
            return a;
    }
    else if (opt == 2)
    {
        do
        {
            cout << endl
                 << "Sorting by ID" << endl
                 << "3. Ascending" << endl
                 << "4. Descending" << endl
                 << "Please enter an instruction : ";
            cin >> opt;
        } while (opt != 3 && opt != 4);
    }
    else if (opt == 3)
    {
        do
        {
            cout << endl
                 << "Sorting by Price" << endl
                 << "5. Ascending" << endl
                 << "6. Descending" << endl
                 << "Please enter an instruction : ";
            cin >> opt;
        } while (opt != 5 && opt != 6);
    }

    if (opt != 0)
        return sortItems(a, opt);
    else
        return a;
}

// Creating new node (Chew Zhi Peng)
Product *initProductNode(string v)
{
    Product *temp;
    temp = new Product;
    temp->next = nullptr;
    temp->product = v;
    return (temp);
}

// Add function (Chew Zhi Peng)
Set addProduct(string p, Set s)
{
    Set temp, head;
    head = s;

    temp = initProductNode(p);
    temp->next = s->next; // if new product is not in the set, the system will add it
    s->next = temp;

    return head;
}

// saving data to file function (Chew Zhi Peng)
void saveSet(Set set)
{
    fstream saveS;
    string new_category;

    saveS.open("itemList.csv", ios::out | ios::app); // open file or create a new file

    set = set->next;
    while (set->product != TAIL)
    {
        if (set->next->product == TAIL)
        {
            saveS << set->product << "";
        }
        else
        {
            saveS << set->product << ",";
        }
        set = set->next;
    }
    saveS << "\n";
    saveS.close();
    cout << "Item added successful";
}

// Edit Function (Chew Zhi Peng)
void editProduct(Set product)
{
    string itemID;

    displayItem(product);

    cout << "=============================================================================================" << endl;
    cout << "Enter 0 to return main" << endl;
    cout << "Please enter the ID of item you wish to edit: ";
    cin >> itemID;

    if (itemID == "0")
    {
        main();
    }

    editSet(itemID, product);
}

// edit from file function (Chew Zhi Peng)
void editSet(string itemID, Set product)
{
    string currentID;
    string command;
    Product *temp;
    Product *temp2;
    temp = product->next;
    temp2 = product->next;
    string id = product->next->productID;

    while (temp && temp->next != nullptr)
    {
        currentID = temp->productID;

        if (itemID == currentID)
        {

            cout << "==============================" << endl;
            cout << "Which Info you wish to update?" << endl;
            cout << "==============================" << endl;
            cout << "Product ID  : " << currentID << endl;
            cout << "1. Product  : " << temp->productName << endl;
            cout << "2. Category : " << temp->productCategory << endl;
            cout << "3. Brand    : " << temp->productBrand << endl;
            cout << "4. Quantity : " << temp->productQuantity << endl;
            cout << "5. Price    : RM" << temp->productPrice << endl;
            cout << "0. Exit to main" << endl;
            cout << "Please enter your choice : ";
            cin >> command;

            cin.ignore();
            if (command == "1")
            {
                while (true)
                {
                    string name;
                    cout << "Enter the new name of the product     : ";
                    getline(cin, name);
                    std::transform(name.begin(), name.end(), name.begin(),
                                   [](unsigned char c)
                                   { return tolower(c); });

                    if (isItemNameExist(name, product))
                    {
                        temp->productName = name;
                        break;
                    }
                    cout << "item name exist, pls create an unique item name" << endl;
                }
            }
            else if (command == "2")
            {
                cout << "Enter the new category of item        : ";
                getline(cin, temp->productCategory);
                std::transform(temp->productCategory.begin(), temp->productCategory.end(), temp->productCategory.begin(),
                               [](unsigned char c)
                               { return tolower(c); });
            }
            else if (command == "3")
            {
                cout << "Enter the new brand of item           : ";
                getline(cin, temp->productBrand);
                std::transform(temp->productBrand.begin(), temp->productBrand.end(), temp->productBrand.begin(),
                               [](unsigned char c)
                               { return tolower(c); });
            }
            else if (command == "4")
            {
                cout << "Enter the new quantity of item        : ";
                cin >> temp->productQuantity;
            }
            else if (command == "5")
            {
                cout << "Enter the new price of item           : ";
                cin >> temp->productPrice;
            }
            else if (command == "0")
            {
                main();
            }
            else
            {
                cout << endl
                     << "Wrong instruction... Please enter again" << endl
                     << endl;
                editSet(itemID, product);
            }

            ofstream edit("itemList.csv");

            while (temp2 && temp2->next != nullptr)
            {
                if (temp2->productID == temp->productID)
                {
                    edit << temp->productID << "," << temp->productName << "," << temp->productCategory << "," << temp->productBrand << "," << temp->productPrice << "," << temp->productQuantity << endl;
                }
                else
                {
                    edit << temp2->productID << "," << temp2->productName << "," << temp2->productCategory << "," << temp2->productBrand << "," << temp2->productPrice << "," << temp2->productQuantity << endl;
                }
                temp2 = temp2->next;
            }

            edit.close();
            cout << "Update Successful" << endl;
            editSet(itemID, product);
        }
        temp = temp->next;
    }

    if (itemID != currentID)
    {
        cout << "Product does not exist..." << endl;
    }

    editProduct(product);
}

// Function to add new node (Chew Zhi Peng)
Product *initLLNode(string pid, string pName, string pCat, string pBrand, float pPrice, int pQuantity)
{
    Product *temp;
    temp = new Product;
    temp->next = nullptr;
    temp->productID = pid;
    temp->productName = pName;
    temp->productCategory = pCat;
    temp->productBrand = pBrand;
    temp->productPrice = pPrice;
    temp->productQuantity = pQuantity;
    return (temp);
}

// Read file function (Ho Ko Ee)
void loadItem(Set a)
{
    // open csv file
    ifstream itemFile;
    itemFile.open("itemList.csv");

    string pid, pName, pCat, pBrand, tempPrice, tempQuantity;
    float pPrice;
    int pQuantity;
    Product *temp;

    while (getline(itemFile, pid, ','))
    {
        getline(itemFile, pName, ',');
        getline(itemFile, pCat, ',');
        getline(itemFile, pBrand, ',');
        getline(itemFile, tempPrice, ',');
        getline(itemFile, tempQuantity, '\n');

        pPrice = std::stof(tempPrice);
        pQuantity = std::stoi(tempQuantity);

        temp = initLLNode(pid, pName, pCat, pBrand, pPrice, pQuantity);
        temp->next = a->next;
        a->next = temp;
    }

    Product *i = a->next;
    Product *j = NULL;
    Product *temp1 = NULL;
    while (i && i->next != NULL)
    {
        j = i->next;
        while (j && j->next != NULL)
        {

            if (i->productName.compare(j->productName) > 0)
            {
                temp1 = initLLNode(i->productID, i->productName, i->productCategory, i->productBrand, i->productPrice, i->productQuantity);

                i->productBrand = j->productBrand;
                i->productCategory = j->productCategory;
                i->productID = j->productID;
                i->productName = j->productName;
                i->productPrice = j->productPrice;
                i->productQuantity = j->productQuantity;

                j->productBrand = temp1->productBrand;
                j->productCategory = temp1->productCategory;
                j->productID = temp1->productID;
                j->productName = temp1->productName;
                j->productPrice = temp1->productPrice;
                j->productQuantity = temp1->productQuantity;
            }
            j = j->next;
        }
        i = i->next;
    }
}

// Display Item List - Inventory (Ho Ko Ee)
void displayItem(Set a)
{
    Product *temp;
    temp = a->next;

    cout << "\n============================================================================================" << endl;
    cout << "                                   Inventory" << endl;
    cout << "=============================================================================================" << endl;

    cout << setw(3) << ""
         << setw(10) << left << "ID"
         << setw(15) << left << "Name"
         << setw(16) << left << "Price"
         << setw(15) << left << "Category"
         << setw(15) << left << "Brand"
         << setw(5) << left << "Quantity" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;

    int i = 1;
    while (temp != NULL)
    {
        if (temp->productName != "")
        {
            cout << setw(1) << left << i << setw(2) << left << "|"
                 << setw(10) << left << temp->productID
                 << setw(15) << left << temp->productName
                 << fixed << setprecision(2) << "MYR " << setw(12) << left << temp->productPrice
                 << setw(15) << left << temp->productCategory
                 << setw(15) << left << temp->productBrand
                 << setw(5) << left << temp->productQuantity << endl;
            i++;
        }
        temp = temp->next;
    }
}

// Display menu (Matthew Labial John)
void displayMenu(Set a)
{
    int opt;

    a = newSet();
    loadItem(a);

    do
    {
        cout << endl
             << "============================" << endl
             << "Display Instruction" << endl
             << "============================" << endl
             << "1. Without sorting" << endl
             << "2. With sorting" << endl
             << "3. Back to main" << endl
             << "Please enter an instruction : ";
        cin >> opt;

    } while (opt != 1 && opt != 2 && opt != 3);

    if (opt == 1)
        displayItem(a);
    else if (opt == 2)
        displayItem(sortInstructions(a));
}

// Search Menu (Ho Ko Ee)
void searchMenu(Set a)
{
    int choice;
    string item;
    int res;

    do
    {
        res = 0;
        cout << endl
             << "==========================================" << endl
             << "                Search Menu               " << endl
             << "==========================================" << endl
             << " 1. Search by ID" << endl
             << " 2. Search by Product Name" << endl
             << " 3. Search by Category" << endl
             << " 4. Search by Brand" << endl
             << " 5. Search by Price" << endl
             << " 6. Back to main" << endl;

        cout << "Enter Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter an ID to search: ";
            getline(cin, item);
            break;
        case 2:
            cout << "Enter a Name to search: ";
            getline(cin, item);
            std::transform(item.begin(), item.end(), item.begin(),
                           [](unsigned char c)
                           { return tolower(c); });
            break;
        case 3:
            cout << "Enter a Category to search: ";
            getline(cin, item);
            std::transform(item.begin(), item.end(), item.begin(),
                           [](unsigned char c)
                           { return tolower(c); });
            break;
        case 4:
            cout << "Enter a Brand to search: ";
            getline(cin, item);
            std::transform(item.begin(), item.end(), item.begin(),
                           [](unsigned char c)
                           { return tolower(c); });
            break;
        case 5:
            item = "pass";
            break;
        case 6:
            main();
            break;
        default:
            cout << "Wrong Selection Please Try again";
            res = -1;
            break;
        }

    } while (res < 0);

    searchItem(choice, item, a);
}

// Search Item (Ho Ko Ee)
void searchItem(int choice, string data, Set a)
{
    Product *temp = NULL;
    Product *curr = a->next;
    Product *temp_curr = NULL;
    switch (choice)
    {
    // searching id
    case 1:
        while (curr)
        {
            if (curr->productID == data)
            {
                temp = initLLNode(curr->productID, curr->productName, curr->productCategory, curr->productBrand, curr->productPrice, curr->productQuantity);
                break;
            }
            curr = curr->next;
        }
        break;
    // searching name
    case 2:
        while (curr)
        {
            if (curr->productName == data)
            {
                temp = initLLNode(curr->productID, curr->productName, curr->productCategory, curr->productBrand, curr->productPrice, curr->productQuantity);
                break;
            }
            curr = curr->next;
        }
        break;
    // searching categories that match
    case 3:
    {
        int i = 0;

        while (curr)
        {
            if (curr->productCategory == data)
            {
                if (i > 0)
                {
                    temp_curr->next = initLLNode(curr->productID, curr->productName, curr->productCategory, curr->productBrand, curr->productPrice, curr->productQuantity);
                    temp_curr = temp_curr->next;
                }
                else
                {
                    temp = initLLNode(curr->productID, curr->productName, curr->productCategory, curr->productBrand, curr->productPrice, curr->productQuantity);
                    temp_curr = temp;
                }
                i += 1;
            }
            curr = curr->next;
        }
        break;
        break;
    }

    // searching brand that match
    case 4:
    {
        int k = 0;
        while (curr)
        {
            if (curr->productBrand == data)
            {
                if (k > 0)
                {
                    temp_curr->next = initLLNode(curr->productID, curr->productName, curr->productCategory, curr->productBrand, curr->productPrice, curr->productQuantity);
                    temp_curr = temp_curr->next;
                }
                else
                {
                    temp = initLLNode(curr->productID, curr->productName, curr->productCategory, curr->productBrand, curr->productPrice, curr->productQuantity);
                    temp_curr = temp;
                }
                k += 1;
            }
            curr = curr->next;
        }
        break;
    }
    // searching Price range
    case 5:
    {
        float minPrice = 0.00;
        float maxPrice = 0.00;

        // getting min and max price from user
        cout << "Enter Price range to search: " << endl;
        cout << "Minimum Price: ";
        cin >> minPrice;
        cout << "Maximum Price: ";
        cin >> maxPrice;

        int i = 0;
        while (curr)
        {
            if (curr->productPrice >= minPrice && curr->productPrice <= maxPrice)
            {
                if (i > 0)
                {
                    temp_curr->next = initLLNode(curr->productID, curr->productName, curr->productCategory, curr->productBrand, curr->productPrice, curr->productQuantity);
                    temp_curr = temp_curr->next;
                }
                else
                {
                    temp = initLLNode(curr->productID, curr->productName, curr->productCategory, curr->productBrand, curr->productPrice, curr->productQuantity);
                    temp_curr = temp;
                }
                i += 1;
            }
            curr = curr->next;
        }
        break;
    }
    }

    curr = temp;

    if (temp)
    {

        cout << "\n============================================================================================" << endl;
        cout << "                                   Inventory" << endl;
        cout << "=============================================================================================" << endl;

        cout << setw(3) << ""
             << setw(10) << left << "ID"
             << setw(15) << left << "Name"
             << setw(16) << left << "Price"
             << setw(15) << left << "Category"
             << setw(15) << left << "Brand"
             << setw(5) << left << "Quantity" << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;

        int i = 1;
        while (curr != NULL)
        {
            if (curr->productName != "")
            {
                cout << setw(1) << left << i << setw(2) << left << "|"
                     << setw(10) << left << curr->productID
                     << setw(15) << left << curr->productName
                     << fixed << setprecision(2) << "MYR " << setw(12) << left << curr->productPrice
                     << setw(15) << left << curr->productCategory
                     << setw(15) << left << curr->productBrand
                     << setw(5) << left << curr->productQuantity << endl;
                i++;
            }
            curr = curr->next;
        }
    }
    else
    {
        cout << "No Record Found . . . " << endl
             << endl;
        main();
    }
}

// Management System Area -- Int main

int main()
{
    Set a = newSet();
    char command;

    loadItem(a);

    while (true)
    {
        displayInstruction();

        cout << "Please enter an instruction : ";
        cin >> command;

        switch (command)
        {
        case '1':
            addInfo(a);
            break;
        case '2':
            editProduct(a);
            break;
        case '3':
            deleteProduct(a);
            break;
        case '4':
            displayMenu(a);
            break;
        case '5':
            searchMenu(a);
            break;
        case '6':
            exit(0);
            break;
        default:
            cout << endl
                 << "Wrong instruction... Please enter again" << endl
                 << endl;
            main();
        }
    }
}
