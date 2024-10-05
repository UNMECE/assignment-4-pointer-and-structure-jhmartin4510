#include <iostream>
#include "item.h"
#include "item_func.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv)
{

Item *list  = new Item[5];	//declaring a Item struct pointer to an array of Item structs

//cout <<"Address of new list is: " <<list <<endl; //diagnostic code to determine that pointer was successfully created

/*Declaring characters arrays for each member of the item objects. Initializing values using a string literal (keeping in mind the null terminating characters included)*/

char SKU1[] = "0001";
char SKU2[] = "0002";
char SKU3[] = "0003";
char SKU4[] = "0004";
char SKU5[]  = "0005";

char cat[] = "Fruit";

char name1[] = "Apple";
char name2[] = "Banana";
char name3[] = "Peach";
char name4[] = "Pear";
char name5[] = "Pineapple";

/*Adding each item to the list array. Can customize category, names, etc... in above code*/
add_item(list, 0.45, SKU1, cat, name1, 0);
add_item(list, 0.30,SKU2, cat, name2, 1);
add_item(list, 0.80, SKU3, cat, name3,  2);
add_item(list, 0.60, SKU4, cat, name4, 3);
add_item(list, 5.99, SKU5, cat, name5, 4);

/*Printing each item from the list.*/
print_items(list,5);

/*Printing the average_price from objects in the list pointer array.*/
cout <<"$$$$$$$$$$$$$$$$$$$$$$$$$" <<endl;
cout <<"The average price is: " <<average_price(list, 5) <<endl;

/*This regards the command line entry by the user to enter an SKU to be searched from the above list*/
char *sku = argv[1];
int ct = 0;	//declaring a count variable to traverse the indices of the list

/*using a while loop to compare the sku string member of the item object to the user-entered sku.
 * If the strcmp() function equates to 0, object index is saved in ct
 * If strcmp() function is not 0, loop continues until ct reaches 5, the size of the list array.*/
while(ct < 5 && strcmp(list[ct].sku,sku)!= 0)
{
	ct++;
}
/*If object is found, ct is less than 5 and ct is used to index the item in the list array and print all members of the item object.*/
if(ct<5)
{
	cout <<":):):):):):):):):):):)" <<endl;
	cout <<"Match found: " <<endl;
	cout <<"Item SKU: " <<list[ct].sku <<endl;
	cout <<"Item Name: " <<list[ct].name <<endl;
	cout <<"Item Category: " <<list[ct].category <<endl;
	cout <<"Item Price: " <<list[ct].price <<endl;
}
/*If object is NOT found, ct reached 5, the program prints the following NOT found message*/
else
{
	cout<<"############################" <<endl;
	cout<<"Sorry, SKU number not found." <<endl;
}

/*once list is done being used, free all members of the item objects in the list that have been dynamically allocated.
 * Also, delete the list array that has been allocated*/
free_items(list, 5);
delete[] list;
/*Confirmation the program completed.*/
cout<<"Program complete!" <<endl;
return 0;
}
