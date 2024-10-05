#include <iostream>
#include "item.h"
#include "item_func.h"
#include <string.h>
using namespace std;

/*This function adds an item object to the pointer array Item_list to the indicated index. The members added to the object are price,sku, category, and name and are dynamically allocated according to the particular size of the string(char array).*/
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
	item_list[index].price = price;
	item_list[index].sku = new char[strlen(sku)+1];	//add 1 to the size of strlen to account for the null terminating character of a string	
	strcpy(item_list[index].sku,sku);	//use strcpy to copy the value of sku parameter to the item_list object 
	item_list[index].category = new char[strlen(category)+1];
	strcpy(item_list[index].category,category);
	item_list[index].name = new char[strlen(name)+1];
	strcpy(item_list[index].name,name);
}
/*This function frees the memory of each object in the item_list pointer array. Size is included to ensure each object of the item_list is deallocated.*/
void free_items(Item *item_list, int size)
{
	for(int i = 0; i<size; i++)
	{
	//	cout <<item_list[i].name <<endl;
		delete[] item_list[i].name;
	//	cout <<item_list[i].name <<endl;
		delete[] item_list[i].category;
		delete[] item_list[i].sku;
	}
}

/*This functions calculates the average price from the price members of the item_list object. It returns a double data type.*/
double average_price(Item *item_list, int size)
{
	double summation = 0;
	for(int i =0; i<size; i++)
	{
		summation += item_list[i].price; 
	}
	return summation/ size;
}
/*This prints each item from the item_list pointer array.*/
void print_items(Item *item_list,int size)
{
	cout <<"Printing all items in this list:" <<endl;
	cout <<"--------------------------------" <<endl;
	for(int i =0; i<size;i++)
	{
		cout<<"------------------------" <<endl;
		cout<<"Item: " <<i <<endl;
		cout<<"Item name: " <<item_list[i].name <<endl;
		cout<<"Item Category: " <<item_list[i].category <<endl;
		cout<<"Item SKU: " <<item_list[i].sku <<endl;
		cout<<"Item Price: " <<item_list[i].price <<endl;
	}
	cout<<"=============" <<endl;
	cout <<"End of list" <<endl;

}
