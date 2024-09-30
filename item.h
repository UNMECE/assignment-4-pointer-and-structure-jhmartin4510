#ifndef _ITEM_H_
#define _ITEM_H_

struct _Item
{
	double price;
	char *sku;
	char *name;
	char *category;
};
typedef struct _Item Item;

#endif
