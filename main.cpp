#include <iostream>
#include "item.h"
#include "item_func.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

main(int argc, char **argv)
{

Item *list  = new Item[5];

cout <<"Address of new list is: " <<list <<endl; 

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

add_item(list, 10.0, SKU1, cat, name1, 0);
add_item(list, 15.0,SKU2, cat, name2, 1);
add_item(list, 20.2, SKU3, cat, name3,  2);
add_item(list, 0.99, SKU4, cat, name4, 3);
add_item(list, 0.75, SKU5, cat, name5, 4);
print_items(list,5);

cout <<"The average price is: " <<average_price(list, 5) <<endl;

char *sku = argv[1];
int ct = 0;

while(ct < 5 && strcmp(list[ct].sku,sku)!= 0)
{
	ct++;
}
if(ct<5)
{
	cout <<":):):):):):):):):):):)" <<endl;
	cout <<"Match found: " <<endl;
	cout <<"Item SKU: " <<list[ct].sku <<endl;
	cout <<"Item Name: " <<list[ct].name <<endl;
	cout <<"Item Category: " <<list[ct].category <<endl;
	cout <<"Item Price: " <<list[ct].price <<endl;
}
else
{
	cout<<"############################" <<endl;
	cout<<"Sorry, SKU number not found." <<endl;
}

free_items(list, 5);
delete[] list;

cout<<"Program complete!" <<endl;
return 0;
}
